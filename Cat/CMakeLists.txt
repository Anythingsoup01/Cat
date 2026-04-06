set(SRCS
    "src/Cat/Core/Application.cpp"
)
add_library(Cat STATIC ${SRCS})
set_property(TARGET Cat PROPERTY CXX_STANDARD 20)

target_precompile_headers(Cat PUBLIC src/ctpch.h)
target_include_directories(Cat PRIVATE
    "src"
)

