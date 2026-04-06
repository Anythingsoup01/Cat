#pragma once

extern Cat::Application *Cat::CreateApplication(const ApplicationCommandlineArgs &args);
bool g_ApplicationRunning = false;

namespace Cat {

int Main(int argc, char **argv) {
  // Initiialize Logger
  g_ApplicationRunning = true;
  while (g_ApplicationRunning) {
    auto app = CreateApplication({argc, argv});

    app->Run();

    delete(app);
  }

  return 0;
}

}

int main(int argc, char **argv) {
  return Cat::Main(argc, argv);
}
