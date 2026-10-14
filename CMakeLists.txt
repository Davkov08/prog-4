cmake_minimum_required(VERSION 4.3)
project(prog_4)

set(CMAKE_CXX_STANDARD 14)

# every main.cpp is its own program, e.g. "BFS - iterative/adj list" -> BFS_iterative_adj_list
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS RELATIVE "${CMAKE_SOURCE_DIR}" "*/main.cpp")
foreach(src ${SOURCES})
    if(src MATCHES "^cmake-build")
        continue()
    endif()
    get_filename_component(dir "${src}" DIRECTORY)
    string(REGEX REPLACE "[^A-Za-z0-9]+" "_" name "${dir}")
    add_executable(${name} "${src}")
endforeach()
