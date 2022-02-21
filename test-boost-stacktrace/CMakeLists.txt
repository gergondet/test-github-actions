cmake_minimum_required(VERSION 3.1)
project(test-macos-boost-backtrace)

include(CTest)
enable_testing()

set(BOOST_STACKTRACE_USE "")
set(BOOST_STACKTRACE_LIB "")

set(variants backtrace addr2line basic)
if(WIN32)
  set(variants windbg ${variants})
endif()

function(search_stacktrace)
  foreach(variant ${variants}})
    find_package(Boost QUIET COMPONENTS stacktrace_${variant})
    string(TOUPPER "${variant}" VARIANT)
    set(check_var Boost_stacktrace_${variant}_FOUND)
    if(Boost_stacktrace_${variant}_FOUND OR Boost_STACKTRACE_${VARIANT}_FOUND)
      set(BOOST_STACKTRACE_USE "BOOST_STACKTRACE_USE_${VARIANT}" PARENT_SCOPE)
      set(BOOST_STACKTRACE_LIB "Boost::stacktrace_${variant}" PARENT_SCOPE)
      find_package(Boost REQUIRED COMPONENTS stacktrace_${variant})
      return()
    endif()
  endforeach()
endfunction()
search_stacktrace()

if(BOOST_STACKTRACE_USE STREQUAL "")
  message(FATAL_ERROR "No suitable Boost.Stacktrace library")
endif()

add_executable(main main.cpp)
target_compile_definitions(main PUBLIC ${BOOST_STACKTRACE_USE})
target_link_libraries(main PUBLIC ${BOOST_STACKTRACE_LIB})

add_test(NAME main COMMAND main)

install(TARGETS main RUNTIME DESTINATION bin)
