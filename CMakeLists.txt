cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# Preproject #

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
# Note: Add something here if you need.

# Project #

# Note: update this to your new project's name and version.
project(
  template
  VERSION 0.0.0
  DESCRIPTION "An empty C++ project as a template"
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

# Note: add other packages here.
find_package(fmt CONFIG REQUIRED)

# Add source files #

set(app_main_source "${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp")
file(GLOB_RECURSE app_sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/source/*/*.cpp")
set(app_include_directory "${CMAKE_CURRENT_SOURCE_DIR}/include")
file(GLOB_RECURSE app_headers CONFIGURE_DEPENDS "${app_include_directory}/*.h")

# Create executable #

add_executable(${PROJECT_NAME} ${app_main_source} ${app_sources} ${app_headers})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD ${CMAKE_CXX_STANDARD})
if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
target_include_directories(${PROJECT_NAME} PRIVATE ${app_include_directory})

# Setup IDE #

if(MSVC)
  set_target_properties(
    ${PROJECT_NAME} PROPERTIES VS_DEBUGGER_ENVIRONMENT "PATH=$(VC_ExecutablePath_x64);%PATH%"
  )
  set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()

# Link libraries #

# Note: use other packages here.
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt-header-only)

# Test #

enable_testing()
add_subdirectory(utest)
