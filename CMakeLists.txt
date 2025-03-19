cmake_minimum_required(VERSION 3.10)

project(echo)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/inc)

add_executable(echo ${PROJECT_SOURCE_DIR}/src/main.cpp)

set_target_properties(echo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
