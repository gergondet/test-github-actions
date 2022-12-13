cmake_minimum_required(VERSION 3.20)

project(MetaProject)
enable_testing()

message(FATAL_ERROR "CMAKE_OSX_DEPLOYMENT_TARGET is ${CMAKE_OSX_DEPLOYMENT_TARGET}")

include(ExternalProject)

execute_process(COMMAND brew install eigen cmake boost ninja)
execute_process(COMMAND python3 -m pip install Cython coverage pytest numpy)

set(CMAKE_ARGS)
list(PREPEND CMAKE_ARGS
  "-DBUILD_TESTING=OFF"
  "-DCMAKE_OSX_DEPLOYMENT_TARGET=${CMAKE_OSX_DEPLOYMENT_TARGET}"
  "-DCMAKE_OSX_ARCHITECTURES=${CMAKE_OSX_ARCHITECTURES}"
  "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
  "-DPYTHON_BINDING_FORCE_PYTHON3:BOOL=ON"
)

ExternalProject_Add(Eigen3ToPython
  GIT_REPOSITORY https://github.com/jrl-umi3218/Eigen3ToPython
  GIT_TAG master
  BINARY_DIR "${PROJECT_BINARY_DIR}/build/Eigen3ToPython"
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -G "Ninja" -B "${PROJECT_BINARY_DIR}/build/Eigen3ToPython" -S "<SOURCE_DIR>" ${CMAKE_ARGS}
  BUILD_COMMAND ${CMAKE_COMMAND} --build <BINARY_DIR> --config $<CONFIG>
  INSTALL_COMMAND sudo ${CMAKE_COMMAND} --build <BINARY_DIR> --config $<CONFIG> --target install
  TEST_COMMAND ${CMAKE_COMMAND} -E true
)
ExternalProject_Add(SpaceVecAlg
  GIT_REPOSITORY https://github.com/jrl-umi3218/SpaceVecAlg
  GIT_TAG master
  BINARY_DIR "${PROJECT_BINARY_DIR}/build/SpaceVecAlg"
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -G "Ninja" -B "${PROJECT_BINARY_DIR}/build/SpaceVecAlg" -S "<SOURCE_DIR>" ${CMAKE_ARGS}
  BUILD_COMMAND ${CMAKE_COMMAND} --build <BINARY_DIR> --config $<CONFIG>
  INSTALL_COMMAND sudo ${CMAKE_COMMAND} --build <BINARY_DIR> --config $<CONFIG> --target install
  TEST_COMMAND ${CMAKE_COMMAND} -E true
)
ExternalProject_Add(sch-core
  GIT_REPOSITORY https://github.com/jrl-umi3218/sch-core
  GIT_TAG master
  BINARY_DIR "${PROJECT_BINARY_DIR}/build/sch-core"
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -G "Ninja" -B "${PROJECT_BINARY_DIR}/build/sch-core" -S "<SOURCE_DIR>" ${CMAKE_ARGS} -DCMAKE_CXX_STANDARD=11
  BUILD_COMMAND ${CMAKE_COMMAND} --build <BINARY_DIR> --config $<CONFIG>
  INSTALL_COMMAND sudo ${CMAKE_COMMAND} --build <BINARY_DIR> --config $<CONFIG> --target install
  TEST_COMMAND ${CMAKE_COMMAND} -E true
)
ExternalProject_Add(sch-core-python
  GIT_REPOSITORY https://github.com/jrl-umi3218/sch-core-python
  GIT_TAG master
  BINARY_DIR "${PROJECT_BINARY_DIR}/build/sch-core-python"
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -G "Ninja" -B "${PROJECT_BINARY_DIR}/build/sch-core-python" -S "<SOURCE_DIR>" ${CMAKE_ARGS}
  BUILD_COMMAND ${CMAKE_COMMAND} --build <BINARY_DIR> --config $<CONFIG>
  INSTALL_COMMAND sudo ${CMAKE_COMMAND} --build <BINARY_DIR> --config $<CONFIG> --target install
  TEST_COMMAND ${CMAKE_COMMAND} -E true
)
