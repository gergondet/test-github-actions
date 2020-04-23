cmake_minimum_required(VERSION 3.1)

enable_testing()

find_package(Boost REQUIRED COMPONENTS unit_test_framework filesystem)

add_executable(myTest myTest.cpp)
target_link_libraries(myTest PUBLIC Boost::unit_test_framework Boost::filesystem)
add_test(myTest myTest)
