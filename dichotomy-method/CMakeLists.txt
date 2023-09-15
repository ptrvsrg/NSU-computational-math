cmake_minimum_required(VERSION 3.22.1)

project(dichotomy-method C)

add_executable(dichotomy-method src/main.c)

target_link_libraries(dichotomy-method PRIVATE m)