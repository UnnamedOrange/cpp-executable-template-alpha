cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# Preproject #

# Add something here if you need.

# Project #

# Note: update this to your new project's name and version.
project(
    template
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

# Note: add other packages here.
find_package(fmt CONFIG REQUIRED)

# Add source files #

file(GLOB_RECURSE app_sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")
file(GLOB_RECURSE app_headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

# Create executable #

add_executable(${PROJECT_NAME} ${sources} ${app_headers})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

# Link libraries #

# Note: add other packages here.
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt-header-only)

# Test #

enable_testing()
add_subdirectory(utest)
