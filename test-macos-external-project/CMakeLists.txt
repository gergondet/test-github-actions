cmake_minimum_required(VERSION 3.20)

project(MetaProject)
enable_testing()

include(ExternalProject)

execute_process(COMMAND brew update)
execute_process(COMMAND brew install eigen)
execute_process(COMMAND brew upgrade eigen)

ExternalProject_Add(SpaceVecAlg
  GIT_REPOSITORY https://github.com/jrl-umi3218/SpaceVecAlg
  GIT_TAG master
  CMAKE_ARGS -DPYTHON_BINDING=OFF
)
