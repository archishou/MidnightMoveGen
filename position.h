//
// Created by Alex Tian on 12/2/2022.
//
#pragma once
#include <string>
#include "constants.h"
#include "types.h"
#include "bitboard.h"
#include "tables.h"

class Position {

public:

    Position() = default;

    BITBOARD pieces[NPIECES]{};

    Piece board[NSQUARES]{};

    Color side = WHITE;

    uint8_t castle_ability_bits = 0;
    Square ep_square = NO_SQUARE;
    HASH_TYPE hash_key = 0;

    BITBOARD get_pieces(Piece piece);
    BITBOARD get_pieces(PieceType piece, Color color);

    BITBOARD get_our_pieces();
    BITBOARD get_opp_pieces();

    BITBOARD get_all_pieces();

    Piece get_piece_standard(Square square);

    void remove_piece(Piece piece, Square square);
    void place_piece(Piece piece, Square square);

    void set_fen(const std::string& fen);

	friend std::ostream& operator<<(std::ostream& os, const Position& p);

    template<Color color, PieceType piece>
    BITBOARD get_piece_attacks(Square square) {
		if constexpr (piece == PAWN) {
			if constexpr (color == WHITE) return WHITE_PAWN_ATTACKS[square];
			return BLACK_PAWN_ATTACKS[square];
		} else if constexpr (piece == KNIGHT) {
			return 0;
		} else if constexpr (piece == BISHOP) {
			return 0;
		} else if constexpr (piece == ROOK) {
			return 0;
		} else if constexpr (piece == QUEEN) {
			return 0;
		} else if constexpr (piece == KING) {
			return 0;
		}
		return 0;
	}

    template<Color color, PieceType piece>
    BITBOARD get_piece_moves(Square square) {
		if constexpr (piece == PAWN) {
			return 0;
		} else if constexpr (piece == KNIGHT) {
			return 0;
		} else if constexpr (piece == BISHOP) {
			return 0;
		} else if constexpr (piece == ROOK) {
			return 0;
		} else if constexpr (piece == QUEEN) {
			return 0;
		} else if constexpr (piece == KING) {
			return 0;
		}
		return 0;
	}
};
