set(SRCS
    "src/CatNip/Core/CatNip.cpp"
)
add_executable(CatNip ${SRCS})
set_property(TARGET CatNip PROPERTY CXX_STANDARD 20)

target_include_directories(CatNip PRIVATE
    "src"
    "${CMAKE_SOURCE_DIR}/Cat/src"
    "${CMAKE_SOURCE_DIR}/vendor/spdlog/include"
)

target_link_libraries(CatNip
    Cat
)

