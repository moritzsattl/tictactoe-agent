add_library(board Board.cpp Board.h
)
target_include_directories(board PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})