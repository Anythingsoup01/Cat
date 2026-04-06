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
  },

  filters = {
    {
      name = "configurations:Debug",
      defines = "C_DEBUG",
    },
    {
      name = "configurations:Release",
      defines = "C_RELEASE",
    }

  }
}
