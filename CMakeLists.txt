cmake_minimum_required(VERSION 3.28)
project(Sudoku_Solver C)

set(CMAKE_C_STANDARD 11)

# Add debug information and disable optimizations
set(CMAKE_C_FLAGS_DEBUG "-g -O0")

# Set the build type to Debug
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif ()

add_executable(
        Sudoku_Solver
        main.c
        test.h
        test.c
        basics/basics.h
        basics/print.h
        basics/print.c
        basics/basic_operations.h
        basics/basic_operations.c
        solvers/basic_solver.h
        solvers/basic_solver.c
        solvers/med_solver.h
        solvers/med_solver.c
)
