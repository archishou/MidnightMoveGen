cmake_minimum_required(VERSION 3.21)
project(MidnightMoveGen)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wno-deprecated")

add_executable(MidnightMoveGen src/position.cpp src/position.h src/constants/misc_constants.h src/utils/helpers.cpp src/utils/helpers.h src/types.h src/types/bitboard.cpp src/types/bitboard.h src/constants/misc_constants.h src/types/move.h tests/board-rep.cpp src/utils/stack.h src/constants/zobrist_constants.h tests/stack.cpp src/types/piece.h src/constants/move_gen_constants.h src/constants/board_masks.h src/constants/move_gen_masks.h src/types/board_rep_types.h src/types/move.cpp)