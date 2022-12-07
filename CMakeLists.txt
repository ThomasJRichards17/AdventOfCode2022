# CMakeList.txt : CMake project for AdventOfCode2022, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("AdventOfCode2022")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory ("Day1")
add_subdirectory ("Day2")
add_subdirectory ("Day3")
add_subdirectory ("Day4")
add_subdirectory ("Day5")
add_subdirectory ("Day6")