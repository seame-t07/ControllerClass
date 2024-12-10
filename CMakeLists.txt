cmake_minimum_required(VERSION 3.10)

# Project name
project(Controller)

# Set C++ standard to C++11 or higher
set(CMAKE_CXX_STANDARD 11)

# Find the SDL2 package
find_package(SDL2 REQUIRED)

# Include directories for the project
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

# List of source files
set(SOURCES
    sources/Controller.cpp
)

# Create a library (static or shared)
add_library(ControllerLib ${SOURCES})

# Link the library with SDL2
target_link_libraries(ControllerLib ${SDL2_LIBRARIES})

# If this project is the top-level project (not included as a submodule)
if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    # Add an executable to test/compile Controller independently
    add_executable(ControllerExec main.cpp)
    target_link_libraries(ControllerExec ControllerLib ${SDL2_LIBRARIES})
endif()

