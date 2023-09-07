cmake_minimum_required(VERSION 3.1)

enable_testing()

set(Boost_VERBOSE ON)
set(Boost_DEBUG ON)
find_package(Boost REQUIRED COMPONENTS unit_test_framework filesystem timer)

add_executable(myTest myTest.cpp)
target_link_libraries(myTest PUBLIC Boost::timer Boost::unit_test_framework Boost::filesystem Boost::disable_autolinking)
target_compile_definitions(myTest PRIVATE -DBOOST_TEST_DYN_LINK)
add_test(myTest myTest)

install(TARGETS myTest DESTINATION bin)
