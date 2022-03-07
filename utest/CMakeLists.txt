cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# Preproject #

if(NOT DEFINED app_sources)
  message(FATAL_ERROR "Using CMake in test folder is not allowed. Please use /CMakeLists.txt.")
endif()

# Note: Add something here if you need.

# Project #

# Note: update this to your new project's name and version.
project(
  utest
  VERSION 0.0.0
  DESCRIPTION "Unit test for the main project"
  HOMEPAGE_URL "https://github.com/UnnamedOrange/cpp-executable-template-alpha"
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

file(GLOB_RECURSE test_sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")

# Create executable #

add_executable(${PROJECT_NAME} ${test_sources} ${app_sources} ${app_headers})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD ${CMAKE_CXX_STANDARD})
if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
target_include_directories(${PROJECT_NAME} PRIVATE ${app_include_directory})

# Link libraries #

# Note: use other packages here.
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt-header-only)
target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main)

# Start test #

gtest_discover_tests(${PROJECT_NAME})
