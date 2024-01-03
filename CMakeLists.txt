cmake_minimum_required(VERSION 3.24)
project(gnl C)

set(CMAKE_C_STANDARD 99)

add_executable(gnl
        pacodir/get_next_line.c
        pacodir/get_next_line.h
        pacodir/get_next_line_utils.c
        wrong_gnl.c)
