cmake_minimum_required(VERSION 3.22)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(csimple)

set(SOURCE_FILES
    main.cpp
    lexer.cpp
    error.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})