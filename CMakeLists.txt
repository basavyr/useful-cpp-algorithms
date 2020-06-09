cmake_minimum_required(VERSION 3.0)

set(project_name "Useful-CPP-Algorithms")

project(project_name)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED TRUE)

SET(CMAKE_MACOSX_RPATH 1) 
SET(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)

add_subdirectory(projects)
