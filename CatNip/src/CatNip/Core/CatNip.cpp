#include "Cat/Core/Application.h"
#include "Cat/Core/Entrypoint.h"

namespace Cat {

Application *CreateApplication(const ApplicationCommandlineArgs &args) {
  ApplicationSpecification spec;
  spec.Name = "CatNip";
  spec.Args = args;

  Application *app = new Application(spec);

  return app;
}

}
