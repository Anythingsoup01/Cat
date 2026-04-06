#include "ctpch.h"
#include "Application.h"

#include <stdio.h>

namespace Cat {

Application::Application(const ApplicationSpecification &spec)
  : m_Specification(spec) {

  printf("Application Start\n");

}

Application::~Application() {

  printf("Application Closed\n");

}

void Application::Run() {
  m_Running = true;
  while (m_Running) {
    printf("Application Update\n");
  }
}

}
