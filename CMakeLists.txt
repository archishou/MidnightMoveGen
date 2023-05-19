cmake_minimum_required(VERSION 3.21)
project(MidnightMoveGen)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wno-deprecated")

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    set(CMAKE_CXX_FLAGS "-fconstexpr-steps=900000000")
else()
    set(CMAKE_CXX_FLAGS "-fconstexpr-ops-limit=900000000")
endif()

add_executable(MidnightMoveGen src/board/position.cpp src/board/position.h src/board/constants/misc_constants.h src/utils/helpers.cpp src/utils/helpers.h src/types.h src/board/types/bitboard.cpp src/board/types/bitboard.h src/board/constants/misc_constants.h src/move_gen/types/move.h tests/board-rep.cpp src/utils/stack.h src/board/constants/zobrist_constants.h tests/stack.cpp src/board/types/piece.h src/board/constants/board_masks.h src/move_gen/move_gen_masks.h src/board/types/board_types.h src/move_gen/move_generator.h src/move_gen/types/types.h src/move_gen/tables/attack_tables.h src/board/types/square.h tests/attacks.cpp src/move_gen/tables/square_tables.h tests/perft.cpp tests/hash.cpp)
add_executable(MidnightMoveGenPrintMoves release/move_gen.h release/print_moves.cpp)
add_executable(MidnightMoveGenPerft release/move_gen.h release/perft.cpp)