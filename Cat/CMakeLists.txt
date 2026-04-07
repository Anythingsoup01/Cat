set(SRCS
    "src/Cat/Core/Window.cpp"
    "src/Cat/Core/Log.cpp"
    "src/Cat/Core/Application.cpp"
)
add_library(Cat STATIC ${SRCS})
set_property(TARGET Cat PROPERTY CXX_STANDARD 20)

target_precompile_headers(Cat PUBLIC src/ctpch.h)
target_include_directories(Cat PRIVATE
    "src"
    "${CMAKE_SOURCE_DIR}/vendor/spdlog/include"
    "${CMAKE_SOURCE_DIR}/vendor/glfw/include"
    "${CMAKE_SOURCE_DIR}/vendor/Glad/include"
    "${CMAKE_SOURCE_DIR}/vendor/yaml-cpp/include"
)

target_link_libraries(Cat
    Glad
    glfw
    GL
    yaml-cpp
)

target_compile_definitions(Cat PUBLIC
    GLFW_INCLUDE_NONE
    CE_DISPLAY_WAYLAND
)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
target_compile_definitions(Cat
PUBLIC
    C_DEBUG
)
endif(CMAKE_BUILD_TYPE STREQUAL Debug)
if(CMAKE_BUILD_TYPE STREQUAL Release)
target_compile_definitions(Cat
PUBLIC
    C_RELEASE
)
endif(CMAKE_BUILD_TYPE STREQUAL Release)
if (UNIX AND NOT APPLE)
target_link_libraries(Cat
    X11
)
endif(UNIX AND NOT APPLE)
