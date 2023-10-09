CMAKE_MINIMUM_REQUIRED(VERSION 3.21.1)

PROJECT(solution-of-equation C)

ADD_EXECUTABLE(solution-of-equation
        src/main.c)

TARGET_LINK_LIBRARIES(solution-of-equation
        PRIVATE m)