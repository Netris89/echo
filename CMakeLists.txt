# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.28)

# Try to find vcpkg on the system by locating the 'vcpkg' executable
find_program(VCPKG_PATH vcpkg)

# If found, derive the root path of vcpkg and set the toolchain file accordingly
if(VCPKG_PATH)
    get_filename_component(VCPKG_ROOT_PATH ${VCPKG_PATH} PATH)
    set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT_PATH}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
# If not found, check if the environment variable VCPKG_ROOT is set and use it
elseif(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
# If neither is found, stop configuration with an error message
else()
    message(FATAL_ERROR "Could not find vcpkg. Please install vcpkg and set the VCPKG_ROOT environment variable.")
endif()

# Define the project name (should come after setting the toolchain file)
project(echo)

# Set the C++ standard to C++20 and enforce it
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Automatically gather all .cpp source files from the 'source' directory
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/source/*.cpp")

# Add the 'include' directory to the list of header search paths
include_directories(${PROJECT_SOURCE_DIR}/include)

# Create an executable target named 'echo' with the source files
add_executable(echo ${SOURCES})

# Set the output directory for the built executable to the 'build' directory
set_target_properties(echo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

# Link the 'echo' executable with GoogleTest libraries
target_link_libraries(echo GTest::gtest GTest::gtest_main)

# Enable testing in the project (required for CTest and GoogleTest integration)
enable_testing()

# Define a test executable target using a test source file
add_executable(test_parser "${PROJECT_SOURCE_DIR}/test/testParser.cpp")

# Link the test executable with GoogleTest
find_package(GTest CONFIG REQUIRED)
target_link_libraries(test_parser PRIVATE GTest::gtest GTest::gtest_main)

# Automatically discover tests from the test executable (requires gtest_main)
include(GoogleTest)
gtest_discover_tests(test_parser)
