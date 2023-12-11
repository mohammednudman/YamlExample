cmake_minimum_required(VERSION 3.8)
project(YamlExample)

add_subdirectory(third-party/yaml-cpp)
add_subdirectory(third-party/googletest)

include_directories(${CMAKE_SOURCE_DIR}/third-party/yaml-cpp/include)

add_executable(
        yaml-example
        main.cpp
        main.h
)

target_link_libraries(
        yaml-example
        PRIVATE
        yaml-cpp
)

add_subdirectory(tests)
