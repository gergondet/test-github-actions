cmake_minimum_required(VERSION 3.1)
project(test-macos-boost-backtrace)

include(CTest)
enable_testing()

set(BOOST_STACKTRACE_USE "")
set(BOOST_STACKTRACE_LIB "")

find_package(Boost COMPONENTS stacktrace_basic)
if(Boost_stacktrace_basic_FOUND)
  message("stacktrace_basic OK")
  set(BOOST_STACKTRACE_USE "BOOST_STACKTRACE_USE_BASIC")
  set(BOOST_STACKTRACE_LIB "Boost::stacktrace_basic")
endif()

find_package(Boost COMPONENTS stacktrace_addr2line)
if(Boost_stacktrace_addr2line_FOUND)
  message("stacktrace_addr2line OK")
  set(BOOST_STACKTRACE_USE "BOOST_STACKTRACE_USE_ADDR2LINE")
  set(BOOST_STACKTRACE_LIB "Boost::stacktrace_addr2line")
endif()

find_package(Boost COMPONENTS stacktrace_windbg)
if(Boost_stacktrace_windbg_FOUND)
  message("stacktrace_windbg OK")
  set(BOOST_STACKTRACE_USE "BOOST_STACKTRACE_USE_WINDBG")
  set(BOOST_STACKTRACE_LIB "Boost::stacktrace_windbg")
endif()

find_package(Boost COMPONENTS stacktrace_backtrace)
if(Boost_stacktrace_backtrace_FOUND)
  message("stacktrace_backtrace OK")
  set(BOOST_STACKTRACE_USE "BOOST_STACKTRACE_USE_BACKTRACE")
  set(BOOST_STACKTRACE_LIB "Boost::stacktrace_backtrace")
endif()

if(BOOST_STACKTRACE_USE STREQUAL "")
  message(FATAL_ERROR "No suitable Boost.Stacktrace library")
endif()

add_executable(main main.cpp)
target_compile_definitions(main PUBLIC ${BOOST_STACKTRACE_USE})
target_link_libraries(main PUBLIC ${BOOST_STACKTRACE_LIB})

add_test(NAME main COMMAND main)

install(TARGETS main RUNTIME DESTINATION bin)
