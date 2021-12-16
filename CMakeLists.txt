project(project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
	src/main.cpp
    src/screwdriver.cpp
    src/carlight.cpp
    src/tools.cpp
    src/mechanic.cpp
    src/functions.cpp

)

cmake_minimum_required(VERSION 3.0)

include_directories(include/)

add_executable(app ${SOURCES})