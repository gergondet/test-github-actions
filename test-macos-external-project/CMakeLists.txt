cmake_minimum_required(VERSION 3.20)

project(MetaProject)
enable_testing()

include(ExternalProject)

execute_process(COMMAND brew update)
execute_process(COMMAND brew uninstall cmake)
execute_process(COMMAND brew install cmake@3.22.0)
execute_process(COMMAND brew install eigen cmake)
execute_process(COMMAND brew upgrade eigen cmake)

ExternalProject_Add(SpaceVecAlg
  GIT_REPOSITORY https://github.com/jrl-umi3218/SpaceVecAlg
  GIT_TAG master
  CMAKE_ARGS -DPYTHON_BINDING=OFF -DBUILD_TESTING=OFF
)
