cmake_minimum_required(VERSION 3.21)
project(MidnightMoveGen)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wno-deprecated")

add_executable(MidnightMoveGen position.cpp position.h constants.h useful.cpp useful.h types.h bitboard.cpp bitboard.h constants.h move.h tests/board-rep.cpp stack.h prng.h zobrist_constants.h)