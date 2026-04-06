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
  },
}
