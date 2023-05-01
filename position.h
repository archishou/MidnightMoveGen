//
// Created by Alex Tian on 12/2/2022.
//

#ifndef BITBOARDENGINE_POSITION_H
#define BITBOARDENGINE_POSITION_H

#include <string>
#include "constants.h"
#include "types.h"
#include "bitboard.h"
#include "tables.h"

class Position {

public:

    Position() = default;
    BITBOARD all_pieces{};
    BITBOARD our_pieces{};
    BITBOARD opp_pieces{};
    BITBOARD empty_squares{};

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

    BITBOARD get_empty_squares();

    Piece get_piece_standard(Square square);

    Square get_king_pos(Color color);

    void remove_piece(Piece piece, Square square);
    void place_piece(Piece piece, Square square);

    void set_fen(const std::string& fen);

	friend std::ostream& operator<<(std::ostream& os, const Position& p);

    BITBOARD get_knight_attacks(Square square);
    BITBOARD get_knight_moves(Square square);

    BITBOARD get_king_attacks(Square square);
    BITBOARD get_king_moves(Square square);

    template<Color color, PieceType piece>
    BITBOARD get_piece_attacks(Square square) {
		if constexpr (piece == PAWN) {
			if constexpr (color == WHITE) return WHITE_PAWN_ATTACKS[square];
			return BLACK_PAWN_ATTACKS[square];
		} else if constexpr (piece == KNIGHT) {
			return get_knight_attacks(square);
		} else if constexpr (piece == BISHOP) {
			return 0;
		} else if constexpr (piece == ROOK) {
			return 0;
		} else if constexpr (piece == QUEEN) {
			return 0;
		} else if constexpr (piece == KING) {
			return get_king_attacks(square);
		}
		return 0;
	}

    template<Color color, PieceType piece>
    BITBOARD get_piece_moves(Square square) {
		if constexpr (piece == PAWN) {
			return 0;
		} else if constexpr (piece == KNIGHT) {
			return get_knight_moves(square);
		} else if constexpr (piece == BISHOP) {
			return 0;
		} else if constexpr (piece == ROOK) {
			return 0;
		} else if constexpr (piece == QUEEN) {
			return 0;
		} else if constexpr (piece == KING) {
			return get_king_moves(square);
		}
		return 0;
	}

    template<Color color>
	BITBOARD get_pseudo_legal_attacks() {
		BITBOARD moves{};

		for (int piece = 0; piece < 6; piece++) {
			BITBOARD piece_bitboard = pieces[piece + side * 6];
			while (piece_bitboard) {
				Square square = poplsb(piece_bitboard);
				moves |= get_piece_attacks<color, piece>(square);
			}
		}

		return moves;
	}

    template<Color color>
	BITBOARD get_pseudo_legal_moves() {
		BITBOARD moves{};

		for (int piece = 0; piece < 6; piece++) {
			BITBOARD piece_bitboard = pieces[piece + side * 6];
			while (piece_bitboard) {
				Square square = poplsb(piece_bitboard);
				moves |= get_piece_moves<color, piece>(square);
			}
		}

		return moves;
	}

};

#endif //BITBOARDENGINE_POSITION_H
