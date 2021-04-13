cmake_minimum_required(VERSION 3.16)
project(PRozp C)

set(CMAKE_C_STANDARD 11)

find_package(MPI REQUIRED)
include_directories(SYSTEM ${MPI_INCLUDE_PATH})

add_subdirectory("lab01")
add_subdirectory("lab02")
add_subdirectory("lab03")
add_subdirectory("lab04")
add_subdirectory("lab05")
