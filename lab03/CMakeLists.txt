cmake_minimum_required(VERSION 3.16)
project(lab03 C)

add_executable(lab03-sequential sequential.c)
target_link_libraries(lab03-sequential PUBLIC crypt)

add_executable(lab03-parallel parallel.c)
target_link_libraries(lab03-parallel PUBLIC crypt MPI::MPI_C)
