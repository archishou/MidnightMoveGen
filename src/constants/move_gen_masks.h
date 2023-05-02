#pragma once

#include "../types/bitboard.h"
#include "../types/board_rep_types.h"

constexpr Bitboard WHITE_OO_BLOCKERS_MASK	= 0x60;
constexpr Bitboard WHITE_OOO_DANGER_MASK	= 0xC;
constexpr Bitboard WHITE_OOO_BLOCKERS_MASK	= 0xE;

constexpr Bitboard BLACK_OO_BLOCKERS_MASK	= 0x6000000000000000;
constexpr Bitboard BLACK_OOO_DANGER_MASK	= 0xE00000000000000;
constexpr Bitboard BLACK_OOO_BLOCKERS_MASK	= 0xC00000000000000;

template<Color C>
Bitboard OO_BLOCKERS_MASK() {
	if constexpr (C == WHITE) return WHITE_OO_BLOCKERS_MASK;
	return BLACK_OO_BLOCKERS_MASK;
}

template<Color C>
Bitboard OOO_DANGER_MASK() {
	if constexpr (C == WHITE) return WHITE_OOO_DANGER_MASK;
	return BLACK_OOO_DANGER_MASK;
}

template<Color C>
Bitboard OOO_BLOCKERS_MASK() {
	if constexpr (C == WHITE) return WHITE_OOO_BLOCKERS_MASK;
	return BLACK_OOO_BLOCKERS_MASK;
}