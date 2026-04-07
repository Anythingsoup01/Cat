#pragma once

#include "Window.h"

#include "Event/ApplicationEvent.h"

namespace Cat {

struct ApplicationCommandlineArgs {
  int Count = 0;
  char** Args = nullptr;

  const char* operator[](int index) const
  {
    if (index >= Count) return "";
    return Args[index];
  }
};

struct ApplicationSpecification {
  std::string Name;
  std::string WorkingDirectory;
  ApplicationCommandlineArgs Args;
};

class Application {
public:
  Application(const ApplicationSpecification &spec);
  ~Application();

  void Run();
private:
  void OnEvent(Event &e);
  bool OnWindowClose(WindowCloseEvent &e);


private:
  Window m_Window;


  ApplicationSpecification m_Specification;
  bool m_Running;
};

Application *CreateApplication(const ApplicationCommandlineArgs &args);

}
