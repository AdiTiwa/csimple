cmake_minimum_required(VERSION 3.22)

add_definitions(-std=c++11)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(csimple)

set(SOURCE_FILES
    main.cpp
    lexer.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})