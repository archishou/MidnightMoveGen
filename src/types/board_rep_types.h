#pragma once
#include "../types.h"

using ZobristHash = u64;
using Bitboard = u64;

constexpr i32 NCOLORS = 2;
enum Color : i32 {
	WHITE,
	BLACK,
};

constexpr Color operator~(Color c) {
	return Color(c ^ BLACK);
}

constexpr i32 NDIRS = 8;
enum Direction : i32 {
	NORTH = 8, NORTH_EAST = 9, EAST = 1, SOUTH_EAST = -7,
	SOUTH = -8, SOUTH_WEST = -9, WEST = -1, NORTH_WEST = 7,
	NORTH_NORTH = 16, SOUTH_SOUTH = -16
};

template<Color C, Direction D>
constexpr Direction relative_dir() {
	if constexpr (C == WHITE) return D;
	return Direction(-D);
}

constexpr i32 NFILES = 8;
using File = i32;

constexpr File AFILE = 0;
constexpr File BFILE = 1;
constexpr File CFILE = 2;
constexpr File DFILE = 3;
constexpr File EFILE = 4;
constexpr File FFILE = 5;
constexpr File GFILE = 6;
constexpr File HFILE = 7;

constexpr i32 NRANKS = 8;
using Rank = i32;

constexpr Rank RANK1 = 0;
constexpr Rank RANK2 = 1;
constexpr Rank RANK3 = 2;
constexpr Rank RANK4 = 3;
constexpr Rank RANK5 = 4;
constexpr Rank RANK6 = 5;
constexpr Rank RANK7 = 6;
constexpr Rank RANK8 = 7;

constexpr i32 NSQUARES = 64;
enum Square : i32 {
	a1, b1, c1, d1, e1, f1, g1, h1,
	a2, b2, c2, d2, e2, f2, g2, h2,
	a3, b3, c3, d3, e3, f3, g3, h3,
	a4, b4, c4, d4, e4, f4, g4, h4,
	a5, b5, c5, d5, e5, f5, g5, h5,
	a6, b6, c6, d6, e6, f6, g6, h6,
	a7, b7, c7, d7, e7, f7, g7, h7,
	a8, b8, c8, d8, e8, f8, g8, h8,
	NO_SQUARE
};

inline Square operator++(Square& orig, int) {
	Square r_val = orig;
	orig = static_cast<Square>(orig + 1);
	return r_val;
}
constexpr Square operator +(Square s, Direction d) { return Square(static_cast<i32>(s) + static_cast<i32>(d)); }
constexpr Square operator -(Square s, Direction d) { return Square(static_cast<i32>(s) - static_cast<i32>(d)); }
inline Square& operator +=(Square& s, Direction d) { return s = s + d; }
inline Square& operator +=(Square& s, i32 i) { return s = static_cast<Square>(s + i); }
inline Square& operator -=(Square& s, Direction d) { return s = s - d; }
inline Square flip(Square s) { return static_cast<Square>(s ^ 0b111000); }

constexpr i32 NCASTLING_RIGHTS = 4;
using CastleRight = i32;

constexpr CastleRight BLACK_OOO = 0b0001;
constexpr CastleRight BLACK_OO	= 0b0010;
constexpr CastleRight WHITE_OOO = 0b0100;
constexpr CastleRight WHITE_OO	= 0b1000;
