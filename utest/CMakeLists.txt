cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# Preproject #

# Add something here if you need.

# Project #

# Note: update this to your new project's name and version.
project(
    utest
    VERSION 0.0.0
    LANGUAGES CXX
)

# Include guards #

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(
        FATAL_ERROR
        "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
    )
endif()

# Find packages #

find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

# Add source files #

set(sources "my_test.cpp")

# Create executable #

add_executable(${PROJECT_NAME} ${sources})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

# Link libraries #

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main)

# Start test #

gtest_discover_tests(${PROJECT_NAME})
