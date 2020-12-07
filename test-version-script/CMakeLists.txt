cmake_minimum_required(VERSION 3.1)
cmake_policy(SET CMP0057 NEW)

project(test-version-script LANGUAGES C CXX)

include(CheckCCompilerFlag)
if(${CMAKE_VERSION} VERSION_GREATER_EQUAL 3.18.0)
  include(CheckLinkerFlag)
endif()

set(VERSION_SCRIPT "${PROJECT_SOURCE_DIR}/version-script.lds")
if(COMMAND check_linker_flag)
  check_linker_flag("C" "-Wl,--version-script=${VERSION_SCRIPT}" HAS_VERSION_SCRIPT_SUPPORT)
else()
  check_c_compiler_flag("-Wl,--version-script=${VERSION_SCRIPT}" HAS_VERSION_SCRIPT_SUPPORT)
endif()

add_executable(main main.cpp)
if(${HAS_VERSION_SCRIPT_SUPPORT})
  set_property(TARGET main APPEND_STRING PROPERTY LINK_FLAGS " -Wl,--version-script=\"${VERSION_SCRIPT}\"")
else()
  message("No version script support")
endif()
