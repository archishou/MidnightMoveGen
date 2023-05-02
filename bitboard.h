#pragma once
#include <cstdint>
#include "types.h"
#include <cassert>

using Bitboard = uint64_t;

constexpr Bitboard MASK_FILE[8] = {
		0x101010101010101, 0x202020202020202, 0x404040404040404, 0x808080808080808,
		0x1010101010101010, 0x2020202020202020, 0x4040404040404040, 0x8080808080808080,
};

void print_bitboard(Bitboard bitboard);

[[nodiscard]] inline Bitboard from_square(Square square) {
	return 1ULL << square;
}

template<Direction D>
[[nodiscard]] constexpr Bitboard shift(Bitboard b) {
	if constexpr (D == NORTH) return b << 8;
	else if constexpr (D == SOUTH) return b >> 8;
	else if constexpr (D == NORTH + NORTH) return b << 16;
	else if constexpr (D == SOUTH + SOUTH) return b >> 16;
	else if constexpr (D == EAST) return (b & ~MASK_FILE[HFILE]) << 1;
	else if constexpr (D == WEST) return (b & ~MASK_FILE[AFILE]) >> 1;
	else if constexpr (D == NORTH_EAST) return (b & ~MASK_FILE[HFILE]) << 9;
	else if constexpr (D == NORTH_WEST) return (b & ~MASK_FILE[AFILE]) << 7;
	else if constexpr (D == SOUTH_EAST) return (b & ~MASK_FILE[HFILE]) >> 7;
	else if constexpr (D == SOUTH_WEST) return (b & ~MASK_FILE[AFILE]) >> 9;
	return 0;
}

template<Color C, Direction D>
[[nodiscard]] constexpr Bitboard shift_relative(Bitboard b) {
	return shift<relative_dir<C, D>()>(b);
}

[[nodiscard]] Square lsb(Bitboard bitboard);
[[nodiscard]] Square msb(Bitboard bitboard);

[[nodiscard]] uint32_t popcount(Bitboard bitboard);
[[nodiscard]] Square poplsb(Bitboard& bitboard);