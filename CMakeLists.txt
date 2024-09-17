cmake_minimum_required(VERSION 3.29)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 26)

add_executable(TicTacToe main.cpp
        board.cpp
        board.h)
