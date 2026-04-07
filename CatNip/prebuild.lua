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
    "${WORKSPACEDIR}vendor/glfw/include",
    "${WORKSPACEDIR}vendor/Glad/include",
    "${WORKSPACEDIR}vendor/yaml-cpp/include",
  },

  links = {
    "Cat",
  },

  filters = {
    {
      name = "configurations:Debug",
      defines = "C_DEBUG",
    },
    {
      name = "configurations:Release",
      defines = "C_RELEASE",
    },
  },
}

