cmake_minimum_required(VERSION 3.16)
project(PRozp C)

set(CMAKE_C_STANDARD 11)

include_directories(/usr/lib/x86_64-linux-gnu/openmpi/include/)
add_executable(lab01 lab01/main.c)
add_executable(lab02 lab02/main.c)
