# min version
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#project name
project(l_systems)

# Add all the source files needed to build the executable
add_executable(
  l_systems
  src/main.cpp
  src/LSystem2D.cpp
)

set_property(TARGET l_systems PROPERTY CXX_STANDARD 17)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT l_systems)