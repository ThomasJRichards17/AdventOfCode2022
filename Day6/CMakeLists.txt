# CMakeList.txt : CMake project for AdventOfCode2022, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable
add_executable (AdventofCodeDay6 "Day6.cpp")

target_compile_options(AdventofCodeDay6 PRIVATE /Wall)