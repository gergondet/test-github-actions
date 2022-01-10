cmake_minimum_required(VERSION 3.20)

project(TestWindowsEnv VERSION 1.0.0 LANGUAGES CXX)

set(BOOST_ROOT "${CMAKE_CURRENT_BINARY_DIR}/Boost/${BOOST_VERSION}/x86_64")
set(ENV{BOOST_ROOT} "${BOOST_ROOT}")
execute_process(COMMAND powershell -c "echo \"BOOST_ROOT=${BOOST_ROOT}\" >> $env:GITHUB_ENV" COMMAND_ERROR_IS_FATAL ANY)
