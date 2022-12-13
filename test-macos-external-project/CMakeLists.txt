cmake_minimum_required(VERSION 3.20)

project(MetaProject)
enable_testing()

message("CMAKE_OSX_DEPLOYMENT_TARGET is ${CMAKE_OSX_DEPLOYMENT_TARGET}")
message("CMAKE_OSX_ARCHITECTURES is ${CMAKE_OSX_ARCHITECTURES}")

include(ExternalProject)

execute_process(COMMAND brew install eigen cmake)

ExternalProject_Add(SpaceVecAlg
  GIT_REPOSITORY https://github.com/jrl-umi3218/SpaceVecAlg
  GIT_TAG master
  CMAKE_ARGS -DPYTHON_BINDING=OFF -DBUILD_TESTING=OFF -DCMAKE_OSX_DEPLOYMENT_TARGET=${CMAKE_OSX_DEPLOYMENT_TARGET} -DCMAKE_OSX_ARCHITECTURES=${CMAKE_OSX_ARCHITECTURES}
)
