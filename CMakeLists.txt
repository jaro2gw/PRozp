cmake_minimum_required(VERSION 3.16)
project(PRozp C)

set(CMAKE_C_STANDARD 11)

find_package(MPI REQUIRED)

set(MPIEXEC mpirun)
set(MPIEXEC_NUMPROC_FLAG -np)
set(MPIEXEC_MAX_NUMPROCS 8)
set(MPIEXEC_PREFLAGS --oversubscribe)

include_directories(SYSTEM ${MPI_INCLUDE_PATH})

add_subdirectory("lab01")
add_subdirectory("lab02")
add_subdirectory("lab03")
add_subdirectory("lab04")
