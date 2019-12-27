# Adapted from https://stackoverflow.com/questions/58844585/use-qwt-installed-via-brew-in-cmake

cmake_minimum_required(VERSION 3.1)
project(FindQwt LANGUAGES CXX)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

if(APPLE)
  set(CMAKE_FIND_FRAMEWORK ONLY)
  find_library(Qwt
    NAMES qwt
    HINTS /usr/local/opt/qwt/lib/
    REQUIRED)
  if(Qwt)
    message("Qwt found: ${Qwt}")
    add_library(Qwt::Qwt UNKNOWN IMPORTED)
    set_target_properties(Qwt::Qwt PROPERTIES
                          INTERFACE_INCLUDE_DIRECTORIES "${Qwt}/Headers"
                          )
    target_link_libraries(Qwt::Qwt INTERFACE ${Qwt})
  else()
    message(FATAL_ERROR "Could not find Qwt on your system")
  endif()
else()
  set(QWT_PATHS
      /usr
      /usr/local/
      /usr/local/share/
      /usr/share/
      "${CMAKE_INSTALL_PREFIX}"
     )

  find_path(Qwt_INCLUDE_DIR
            NAMES qwt.h
            PATHS ${QWT_PATHS}
            HINTS ${QWT_HINTS}
            PATH_SUFFIXES include qwt-qt4 qwt-qt5 qwt Headers
            DOC "Variable storing the location of Qwt header"
           )

  find_library(Qwt_LIBRARY
               NAMES qwt qwt-qt4 qwt-qt5
               PATHS ${QWT_PATHS}
               HINTS ${QWT_HINTS}
               PATH_SUFFIXES ${ARCH_SUFFIX}
               DOC "Variable storing the location of Qwt library"
              )

  set(Qwt_VERSION ${Qwt_FIND_VERSION})
  include(FindPackageHandleStandardArgs)
  find_package_handle_standard_args(Qwt
                                    FOUND_VAR Qwt_FOUND
                                    REQUIRED_VARS
                                    Qwt_LIBRARY
                                    Qwt_INCLUDE_DIR
                                    VERSION_VAR Qwt_VERSION
                                   )

  if(Qwt_FOUND)
    set(Qwt_LIBRARIES ${Qwt_LIBRARY})
    set(Qwt_INCLUDE_DIRS ${Qwt_INCLUDE_DIR})
  else()
    message(FATAL_ERROR "Could not find Qwt on your system")
  endif()
  if(Qwt_FOUND AND NOT TARGET Qwt::Qwt)
    add_library(Qwt::Qwt UNKNOWN IMPORTED)
    set_target_properties(Qwt::Qwt PROPERTIES
                          IMPORTED_LOCATION "${Qwt_LIBRARIES}"
                          INTERFACE_COMPILE_OPTIONS ""
                          INTERFACE_INCLUDE_DIRECTORIES "${Qwt_INCLUDE_DIR}"
                          )
  endif()
endif()

add_executable(main main.cpp)
target_link_libraries(main PUBLIC Qwt::Qwt Qt5::Widgets)
