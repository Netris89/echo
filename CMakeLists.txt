# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.28)

# Define the project name
project(echo)

# Set the C++ standard to C++20 and enforce it
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Automatically gather all .cpp source files from the 'source' directory
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/source/*.cpp")

# Add the 'include' directory to the list of header search paths
include_directories(${PROJECT_SOURCE_DIR}/include)

# Create the executable target for your main program
add_executable(echo ${SOURCES})

# Enable testing in the project (required for CTest and GoogleTest integration)
# enable_testing()
# include(GoogleTest)

# # Create the test executable
# add_executable(testParser "${PROJECT_SOURCE_DIR}/test/testParser.cpp")

# # Include GoogleTest headers and libraries installed via MSYS
# include_directories(/mingw64/include)
# link_directories(/mingw64/lib)

# Create a library target to reuse in the the test target
# add_library(parser_lib ${SOURCES})

# set_target_properties(testParser PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

# # Link with GoogleTest
# target_link_libraries(testParser PRIVATE parser_lib gtest gtest_main)

# # # Automatically discover tests from the test executable (requires gtest_main)
# gtest_discover_tests(testParser)
