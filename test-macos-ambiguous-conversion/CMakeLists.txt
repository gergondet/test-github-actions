cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)

project(MacOSConversion LANGUAGES CXX VERSION 1.0.0)

enable_testing()

add_executable(main main.cpp)
add_test(main main)
