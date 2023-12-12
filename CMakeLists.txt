cmake_minimum_required(VERSION 3.10)
project(YamlExample)

add_subdirectory(third-party/yaml-cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

include_directories(${CMAKE_SOURCE_DIR}/third-party/yaml-cpp/include)

add_executable(
        bonus_calculator
        employee_bonus.h
        employee_bonus.cpp
        main.cpp
)

add_executable(
        test_main
        test_main.cpp
        employee_bonus.cpp
        employee_bonus.h
)
target_link_libraries(test_main PRIVATE yaml-cpp gtest gmock)
target_include_directories(test_main PRIVATE ${CMAKE_SOURCE_DIR}/third-party/yaml-cpp/include)

target_link_libraries(
        bonus_calculator
        PRIVATE
        yaml-cpp
)

add_custom_target(tests COMMAND test_main)
