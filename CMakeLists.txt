cmake_minimum_required(VERSION 3.21)
project(BitboardEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wno-deprecated")

add_executable(BitboardEngine position.cpp position.h constants.h useful.cpp useful.h types.cpp types.h bitboard.cpp bitboard.h tables.h move.cpp move.h tests/board-rep.cpp)
