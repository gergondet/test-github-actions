cmake_minimum_required(VERSION 3.1)

enable_testing()

set(Boost_VERBOSE ON)
set(Boost_DEBUG ON)
find_package(Boost REQUIRED COMPONENTS unit_test_framework filesystem)

add_executable(myTest myTest.cpp)
target_link_libraries(myTest PUBLIC Boost::unit_test_framework Boost::filesystem Boost::disable_autolinking)
add_test(myTest myTest)

install(TARGETS myTest DESTINATION bin)
