cmake_minimum_required(VERSION 3.7)
project(argparser)

set(CMAKE_CXX_STANDARD 1z)

set(SOURCE_FILES
        ArgParser.cpp
        ArgParser.h
        main.cpp)

add_executable(argparser ${SOURCE_FILES})