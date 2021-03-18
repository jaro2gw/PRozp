cmake_minimum_required(VERSION 3.16)
project(lab02 C)

add_executable(lab02 main.c)
target_link_libraries(lab02 PUBLIC MPI::MPI_C)
configure_file(nums nums COPYONLY)
