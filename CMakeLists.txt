# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.28)

# Define the project name
project(echo)

# Set the C++ standard to C++20 and make it a required standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Use file globbing to include all .cpp files from the src directory
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Include the header files located in the 'inc' directory
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Create an executable called 'echo' using the listed source files
add_executable(echo ${SOURCES})

# Set the output directory for the executable to 'bin' inside the project source directory
set_target_properties(echo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
