# min version
cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules")

#resolve cairo package
find_package(Cairo REQUIRED)

#project name
project(l_systems)

# Add all the source files needed to build the executable
add_executable(
  l_systems

  src/main.cpp

  src/production.hpp
  src/command-mapper.hpp
  src/l-system.hpp
  src/l-system-generation.hpp  
  src/cairo-turtle.hpp
  src/file-handler.hpp
  src/state.hpp
  src/test-turtle.hpp
  src/turtle.hpp
)

link_directories(${Cairo_INCLUDE_DIRS})
target_include_directories(l_systems PRIVATE ${Cairo_INCLUDE_DIRS})
target_link_libraries(l_systems PRIVATE ${Cairo_LIBS})

# use c++ 17
set_property(TARGET l_systems PROPERTY CXX_STANDARD 17)

# windows handling
if(WIN32)

    # set the correct startup project in visual studio
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT l_systems)

    # Copy Cairo DLL to output folder on Windows
    foreach(DLL ${Cairo_DLLS})
        add_custom_command(TARGET l_systems POST_BUILD COMMAND
            ${CMAKE_COMMAND} -E copy_if_different ${DLL} $<TARGET_FILE_DIR:l_systems>)
    endforeach()
endif()


#Source for cmake + dlls: https://github.com/preshing/CairoSample/blob/master/CMakeLists.txt