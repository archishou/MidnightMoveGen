#pragma once

#include "../types.h"

constexpr u32 NPIECE_TYPES = 7;
enum PieceType : u32 {
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING,
	NO_PIECE_TYPE
};

constexpr i8 NPIECES = 15;
enum Piece : u32 {
	WHITE_PAWN,
	WHITE_KNIGHT,
	WHITE_BISHOP,
	WHITE_ROOK,
	WHITE_QUEEN,
	WHITE_KING,
	BLACK_PAWN = 8,
	BLACK_KNIGHT,
	BLACK_BISHOP,
	BLACK_ROOK,
	BLACK_QUEEN,
	BLACK_KING,
	EMPTY,
};

template<Color color, PieceType piece_type>
Piece make_piece() {
	return static_cast<Piece>((color << 3) | piece_type);
}