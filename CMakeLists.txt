cmake_minimum_required(VERSION 3.24)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled Src/main.c Inc/cura.h Src/cura.c
)
include_directories(D:/untitled/Inc)
