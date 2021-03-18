cmake_minimum_required(VERSION 3.16)
project(lab01 C)

add_executable(lab01 main.c)
target_link_libraries(lab01 PUBLIC MPI::MPI_C)
