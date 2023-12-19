cmake_minimum_required(VERSION 3.22.1)

project(difference-schemes C)

add_executable(difference-schemes
        src/godunov_schema.c
        src/csv.c
        src/thomas_algorithm.c
        src/main.c
        src/implicit_schema.c)
target_include_directories(difference-schemes
        PRIVATE include)
target_compile_options(difference-schemes
        PRIVATE -O2)