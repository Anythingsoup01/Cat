#include "ctpch.h"
#include "Window.h"

// Event
#include "Event/ApplicationEvent.h"
#include "Event/KeyEvent.h"
#include "Event/MouseEvent.h"

#include <yaml-cpp/yaml.h>

namespace Cat {

// Setting GLFW Functions and Variables
static bool s_GLFWInitialized = false;

static void GLFWErrorCallback(int error, const char* description) {
  C_API_ERROR("GLFW Error ({0}) : {1}", error, description);
}

Window::~Window()
{
  glfwDestroyWindow(m_Window);
  SerializeWindowData();
}

void Window::Init()
{

  if (!DeserializeWindowData()) {
    m_Data.Height = 720;
    m_Data.Width = 1280;
    m_Data.Title = "Cat Game Engine";
    m_Data.VSync = false;
  }

  C_API_INFO("Creating Window {0}({1}, {2})", m_Data.Title, m_Data.Width, m_Data.Height);


  // Initializing GLFW
  if (!s_GLFWInitialized) {
    int success = glfwInit();
    glfwSetErrorCallback(GLFWErrorCallback);
    C_API_ASSERT(success, "Could not load GLFW!");
    s_GLFWInitialized = true;
  }

  m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
  glfwMakeContextCurrent(m_Window);

  //m_Context = GraphicsContext::Create();
  //m_Context->MakeContextCurrent(m_Window);
  //m_Context->Init();

  glfwSetWindowUserPointer(m_Window, &m_Data);

  // Setting GLFW Callbacks-------------------------------------------------------------------

  // Close Callback
  glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) 
  {
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
    WindowCloseEvent event;
    data.EventCallback(event);
  });

  // Resize Callback
  glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) 
  {
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
    data.Width = width;
    data.Height = height;


    WindowResizeEvent event(width, height);


    data.EventCallback(event);
  });

  // Focus Callback
  glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused) 
  {
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
    if(focused) {
      WindowFocusEvent event;
      data.EventCallback(event);
    } else {
      WindowLostFocusEvent event;
      data.EventCallback(event);
    }
  });


  // Key Callback
  glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) 
  {
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
    switch (action)
    {
      case GLFW_PRESS: 
      {
        KeyPressedEvent event((KeyCode)key, 0);
        data.EventCallback(event);
        break;
      }
      case GLFW_RELEASE:
      {
        KeyReleasedEvent event((KeyCode)key);
        data.EventCallback(event);
        break;
      }
      case GLFW_REPEAT:
      {
        KeyPressedEvent event((KeyCode)key, true);
        data.EventCallback(event);
        break;
      }
    }
  });

  // Key Typed Callback
  glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int codepoint) {
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
    KeyTypedEvent event((KeyCode)codepoint);
    data.EventCallback(event);
  });

  // Mouse Callback
  glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) 
  {
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
    switch (action)
    {
      case GLFW_PRESS:
      {
        MouseButtonPressedEvent event((MouseCode)button);
        data.EventCallback(event);
        break;
      }
      case GLFW_RELEASE:
      {
        MouseButtonReleasedEvent event((MouseCode)button);
        data.EventCallback(event);
        break;
      }
      case GLFW_REPEAT:
      {
        MouseButtonPressedEvent event((MouseCode)button);
        data.EventCallback(event);
        break;
      }
    }
  });

  // Mouse Scroll Callback
  glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset) {
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
    MouseScrolledEvent event((float)xoffset, (float)yoffset);
    data.EventCallback(event);
  });

  // Mouse Position Callback
  glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
    MouseMovedEvent event((const float)(unsigned int)xpos, (const float)(unsigned int)ypos);
    data.EventCallback(event);
  });
}

void Window::OnUpdate() {
  glfwPollEvents();
  glfwSwapBuffers(m_Window);
  //m_Context->SwapBuffers();
}
void Window::SetVSync(bool enabled) {
  if (enabled) glfwSwapInterval(1);
  else glfwSwapInterval(0);
  m_Data.VSync = enabled;
}

bool Window::DeserializeWindowData() {
  YAML::Node data;
  try {
    data = YAML::LoadFile(".editor/win_data.yaml");
  } catch (YAML::ParserException ex) {
    C_API_ERROR("Failed to load .editor/win_data.yaml file\n       {0}", ex.what());
    return false;
  } catch (std::exception ex) {
    C_API_ERROR("Failed to load .editor/win_data.yaml file\n       {0}", ex.what());
    return false;
  }

  auto node = data["Data"];
  if (!node)
    return false;

  m_Data.Height = node["Height"].as<uint32_t>();
  m_Data.Width = node["Width"].as<uint32_t>();
  m_Data.Title = node["Title"].as<std::string>();
  m_Data.VSync = node["VSync"].as<bool>();

  return true;
}

void Window::SerializeWindowData() {
  YAML::Emitter out;
  out << YAML::BeginMap; // Root
  out << YAML::Key << "Data" << YAML::Value;
  out << YAML::BeginMap; // Data
  out << YAML::Key << "Height" << YAML::Value << m_Data.Height;
  out << YAML::Key << "Width" << YAML::Value << m_Data.Width;
  out << YAML::Key << "Title" << YAML::Value << m_Data.Title;
  out << YAML::Key << "VSync" << YAML::Value << m_Data.VSync;
  out << YAML::EndMap;

  std::ofstream fout(".editor/win_data.yaml");
  fout << out.c_str();
  fout.close();
}

}
