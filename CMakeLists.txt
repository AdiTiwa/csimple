cmake_minimum_required(VERSION 3.22)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(csimple)

set(SOURCE_FILES
    token.cpp
    error.cpp
    lexer.cpp
    parser.cpp
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})