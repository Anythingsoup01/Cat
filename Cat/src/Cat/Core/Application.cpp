#include "ctpch.h"
#include "Application.h"

#include <stdio.h>

extern bool g_ApplicationRunning;

namespace Cat {

Application::Application(const ApplicationSpecification &spec)
  : m_Specification(spec) {

  C_API_INFO("Application Initialized");
  m_Window.SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
  m_Window.Init();
  m_Window.SetVSync(false);
}

Application::~Application() {

  g_ApplicationRunning = false;

}

void Application::Run() {
  m_Running = true;
  while (m_Running) {
    m_Window.OnUpdate();
  }
}

void Application::OnEvent(Event &e) {
  EventDispatcher dispatcher(e);
  dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
}

bool Application::OnWindowClose(WindowCloseEvent& e)
{
  m_Running = false;
  return true;
}



}
