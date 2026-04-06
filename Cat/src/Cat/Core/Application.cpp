#include "ctpch.h"
#include "Application.h"

#include <stdio.h>

namespace Cat {

Application::Application(const ApplicationSpecification &spec)
  : m_Specification(spec) {

  C_API_INFO("Application Initialized");

}

Application::~Application() {

  C_API_INFO("Application Update");

}

void Application::Run() {
  m_Running = true;
  while (m_Running) {
  }
}

}
