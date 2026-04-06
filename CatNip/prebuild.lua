Project = {
  name = "CatNip",
  kind = "ConsoleApp",
  language = "C++",
  dialect = "20",

  files = {
    "src/*.cpp",
  },

  includedirs = {
    "src",
    "${WORKSPACEDIR}Cat/src",
    "${WORKSPACEDIR}vendor/spdlog/include",
  },

  links = {
    "Cat",
  },

}

