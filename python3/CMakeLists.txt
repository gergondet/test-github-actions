cmake_minimum_required(VERSION 2.8)

project(Dummy LANGUAGES CXX)

add_custom_target(WhereIsPythonInCMake ALL COMMAND which python3)
add_custom_target(WhatIsPythonInCMake ALL COMMAND python3 --version DEPENDS WhereIsPythonInCMake)
