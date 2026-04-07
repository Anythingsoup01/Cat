set(SRCS
    "src/CatNip/Core/CatNip.cpp"
)
add_executable(CatNip ${SRCS})
set_property(TARGET CatNip PROPERTY CXX_STANDARD 20)

target_include_directories(CatNip PRIVATE
    "src"
    "${CMAKE_SOURCE_DIR}/Cat/src"
    "${CMAKE_SOURCE_DIR}/vendor/spdlog/include"
    "${CMAKE_SOURCE_DIR}/vendor/glfw/include"
    "${CMAKE_SOURCE_DIR}/vendor/Glad/include"
    "${CMAKE_SOURCE_DIR}/vendor/yaml-cpp/include"
)

target_link_libraries(CatNip
    Cat
)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
target_compile_definitions(CatNip
PUBLIC
    C_DEBUG
)
endif(CMAKE_BUILD_TYPE STREQUAL Debug)
if(CMAKE_BUILD_TYPE STREQUAL Release)
target_compile_definitions(CatNip
PUBLIC
    C_RELEASE
)
endif(CMAKE_BUILD_TYPE STREQUAL Release)
