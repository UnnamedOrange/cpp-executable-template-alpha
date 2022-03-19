cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# Preproject #

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
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

set(app_main_source "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
file(GLOB_RECURSE app_sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*/*.cpp")
set(app_include_directory "${CMAKE_CURRENT_SOURCE_DIR}/include")
configure_file(
  "${app_include_directory}/app_config.hpp.in" "${CMAKE_BINARY_DIR}/include/app_config.hpp"
  ESCAPE_QUOTES
)
file(GLOB_RECURSE app_headers_h CONFIGURE_DEPENDS "${app_include_directory}/*.h")
file(GLOB_RECURSE app_headers_hpp CONFIGURE_DEPENDS "${app_include_directory}/*.hpp")

# Create executable #

add_executable(
  ${PROJECT_NAME} ${app_main_source} ${app_sources} ${app_headers_h} ${app_headers_hpp}
)
set_target_properties(
  ${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD ${CMAKE_CXX_STANDARD})
if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
  target_compile_options(${PROJECT_NAME} PRIVATE /permissive)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
target_include_directories(${PROJECT_NAME} PRIVATE ${app_include_directory})
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_BINARY_DIR}/include")

# Copy assets #

file(GLOB_RECURSE asset_files "${CMAKE_CURRENT_SOURCE_DIR}/asset/*")
foreach(one_asset_file ${asset_files})
  file(RELATIVE_PATH asset_relative "${CMAKE_CURRENT_SOURCE_DIR}/asset/" "${one_asset_file}")
  set(asset_destination "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${asset_relative}")
  get_filename_component(asset_destination_dir "${asset_destination}" DIRECTORY)
  add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${asset_destination_dir}
  )
  add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${one_asset_file} ${asset_destination_dir}
  )
endforeach()

# Set sanitizer #

target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=address>)
target_link_options(
  ${PROJECT_NAME} PRIVATE
  $<$<AND:$<NOT:$<CXX_COMPILER_ID:MSVC>>,$<CONFIG:Debug>>:-fsanitize=address>
)

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
