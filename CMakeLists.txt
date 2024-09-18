cmake_minimum_required(VERSION 3.28)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 26)

add_subdirectory(src)

add_executable(TicTacToe main.cpp
        src/Agent.cpp
        src/Agent.h)
target_link_libraries(TicTacToe PRIVATE board)

add_subdirectory(test)