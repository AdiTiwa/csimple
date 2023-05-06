cmake_minimum_required(VERSION 3.22)

add_definitions(-std=c++11)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(csimple)

add_executable(main
    main.cpp
    lexer.cpp
    Token.cpp
    lexer.h
    token.h
)