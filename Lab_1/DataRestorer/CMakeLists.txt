cmake_minimum_required(VERSION 3.21)
project(DataRestorer)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataRestorer
        main.cpp
        ImageRestorer.h
        ImageWriter.h
        ImageRestorer.cpp
        ImageWriter.cpp)
