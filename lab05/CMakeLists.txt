cmake_minimum_required(VERSION 3.16)
project(lab05 C)

add_executable(lab05
        main.c
        main.h
        monitor.c
        monitor.h
        watek_glowny.c
        watek_glowny.h
        watek_komunikacyjny.c
        watek_komunikacyjny.h
        )
target_link_libraries(lab05 PUBLIC MPI::MPI_C)
