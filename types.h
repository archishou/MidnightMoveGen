#ifndef TYPES_H
#define TYPES_H

#include <cstdint>

enum Color : int {
	WHITE,
	BLACK,
};

constexpr Color operator~(Color c) {
	return Color(c ^ BLACK);
}

constexpr uint32_t NPIECES = 13;
enum Piece : uint32_t {
	WHITE_PAWN,
	WHITE_KNIGHT,
	WHITE_BISHOP,
	WHITE_ROOK,
	WHITE_QUEEN,
	WHITE_KING,
	BLACK_PAWN,
	BLACK_KNIGHT,
	BLACK_BISHOP,
	BLACK_ROOK,
	BLACK_QUEEN,
	BLACK_KING,
	EMPTY,
};

constexpr uint32_t NSQUARES = 64;
enum Square : uint32_t {
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

enum PieceType : uint32_t {
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING
};

const uint32_t NDIRS = 8;
enum Direction : int32_t {
	NORTH = 8, NORTH_EAST = 9, EAST = 1, SOUTH_EAST = -7,
	SOUTH = -8, SOUTH_WEST = -9, WEST = -1, NORTH_WEST = 7,
	NORTH_NORTH = 16, SOUTH_SOUTH = -16
};

const uint32_t NFILES = 8;
using File = uint32_t;

constexpr File AFILE = 0;
constexpr File BFILE = 1;
constexpr File CFILE = 2;
constexpr File DFILE = 3;
constexpr File EFILE = 4;
constexpr File FFILE = 5;
constexpr File GFILE = 6;
constexpr File HFILE = 7;

const uint32_t NRANKS = 8;
using Rank = uint32_t;

constexpr Rank RANK1 = 0;
constexpr Rank RANK2 = 1;
constexpr Rank RANK3 = 2;
constexpr Rank RANK4 = 3;
constexpr Rank RANK5 = 4;
constexpr Rank RANK6 = 5;
constexpr Rank RANK7 = 6;
constexpr Rank RANK8 = 7;

using PLY_TYPE = uint32_t;
using HASH_TYPE = uint64_t;
#endif // TYPES_H