#pragma once

#include "ctpch.h"

#include "Event/Event.h"

#include <GLFW/glfw3.h>


namespace Cat {

class Window {
public:
  using EventCallbackFn = std::function<void(Event&)>;
  void Init();
  ~Window();

  void OnUpdate();

  unsigned int GetWidth() const { return m_Data.Width; }
  unsigned int GetHeight() const { return m_Data.Height; }

  void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }
  void SetVSync(bool enabled);
  bool IsVSync() const { return m_Data.VSync; }

  GLFWwindow* Get() { return m_Window; }

private:
  GLFWwindow* m_Window;

  struct WindowData {
    std::string Title;
    unsigned int Width, Height;
    bool VSync;
    EventCallbackFn EventCallback;
  };

  WindowData m_Data;

private:
  bool DeserializeWindowData();
  void SerializeWindowData();

};

}
