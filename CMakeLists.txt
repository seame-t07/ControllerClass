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
    main.cpp
    sources/Controller.cpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link with SDL2
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

# Create a library instead of an executable
add_library(ControllerLib ${SOURCES})

