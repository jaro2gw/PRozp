cmake_minimum_required(VERSION 3.16)
project(lab04 C)

add_executable(lab04 main.c)
target_link_libraries(lab04 PUBLIC MPI::MPI_C)
