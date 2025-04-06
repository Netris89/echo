# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.28)

# Define the project name
project(echo)

# Set the C++ standard to C++20 and make it a required standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Use file globbing to include all .cpp files from the src directory
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Try to find vcpkg on the system
find_program(VCPKG_PATH vcpkg REQUIRED)

# If found, set the vcpkg toolchain file dynamically
if(VCPKG_PATH)
    get_filename_component(VCPKG_ROOT_PATH ${VCPKG_PATH} PATH)
    set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT_PATH}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
else()
    message(FATAL_ERROR "Could not find vcpkg. Please install vcpkg and set the VCPKG_ROOT environment variable.")
endif()

# Include the header files located in the 'inc' directory
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Find GoogleTest package (ensures GTest is available)
find_package(GTest REQUIRED)

# Create an executable called 'echo' using the listed source files
add_executable(echo ${SOURCES})

# Set the output directory for the executable to 'bin' inside the project source directory
set_target_properties(echo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Link the executable with the GoogleTest libraries
target_link_libraries(echo GTest::GTest GTest::Main)
