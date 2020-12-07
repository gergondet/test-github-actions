cmake_minimum_required(VERSION 3.1)

project(test-version-script LANGUAGES C CXX)

include(CheckCCompilerFlag)

set(VERSION_SCRIPT "${PROJECT_SOURCE_DIR}/version-script.lds")
check_c_compiler_flag("-Wl,--version-script=\"${VERSION_SCRIPT}\"" HAS_VERSION_SCRIPT_SUPPORT)

add_executable(main main.cpp)
if(${HAS_VERSION_SCRIPT_SUPPORT})
  set_property(TARGET main APPEND_STRING PROPERTY LINK_FLAGS " -Wl,--version-script=\"${VERSION_SCRIPT}\"")
else()
  message("No version script support")
endif()
