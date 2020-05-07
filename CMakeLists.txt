cmake_minimum_required(VERSION 3.10)
project(TravelingSalesman)
set (EXE_NAME TSP)

set (input01 "input.txt")
set (input02 "")
set (input03 "")
set (input04 "")

##########################################

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03 input04)
    configure_file(${file} ${file} COPYONLY)
endforeach()

##########################################

set(CMAKE_CXX_STANDARD 14)

add_executable(TravelingSalesman main.cpp TSP.cpp TSP.h)