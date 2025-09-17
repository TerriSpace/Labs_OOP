cmake_minimum_required(VERSION 3.10)
project(Lab1oop)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(LabLoop main.cpp src/functions.cpp)

# Google Test integration через Git
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)
FetchContent_MakeAvailable(googletest)

# Тестовый исполняемый файл
add_executable(tests01 tests/tests01.cpp src/functions.cpp)
target_link_libraries(tests01 PRIVATE gtest_main)
target_include_directories(tests01 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})