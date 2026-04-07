Project = {
  name = "Cat",
  kind = "StaticLib",
  language = "C++",
  dialect = "20",

  pch = "src/ctpch.h",

  files = {
    "src/*.cpp",
  },

  includedirs = {
    "src",
    "${WORKSPACEDIR}vendor/spdlog/include",
    "${WORKSPACEDIR}vendor/glfw/include",
    "${WORKSPACEDIR}vendor/Glad/include",
    "${WORKSPACEDIR}vendor/yaml-cpp/include",
  },

  links = {
    "Glad",
    "glfw",
    "GL",
    "yaml-cpp"
  },

  defines = {
    "GLFW_INCLUDE_NONE",
    "CE_DISPLAY_WAYLAND",
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
    {
      name = "system:linux",
      links = "X11",
    },

  }
}
