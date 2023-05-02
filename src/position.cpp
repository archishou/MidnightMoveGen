//
// Created by Alex Tian on 12/2/2022.
//

#include <stdexcept>
#include <iostream>
#include "position.h"
#include "utils/helpers.h"
#include "types/bitboard.h"
#include "constants/misc_constants.h"

void Position::remove_piece(Piece piece, Square square) {
    pieces[piece] &= ~(1ULL << square);
    board[square] = EMPTY;
}

void Position::place_piece(Piece piece, Square square) {
    pieces[piece] |= (1ULL << square);
    board[square] = piece;
}

void Position::set_fen(const std::string& fen_string) {
	reset();
    std::vector<std::string> fen_tokens = split(fen_string, " ");

    if (fen_tokens.size() < 4) {
        throw std::invalid_argument( "Fen is incorrect" );
    }

    const std::string position = fen_tokens[0];
    const std::string player = fen_tokens[1];
    const std::string castling = fen_tokens[2];
    const std::string en_passant = fen_tokens[3];

    const std::string half_move_clock = fen_tokens.size() > 4 ? fen_tokens[4] : "0";
    const std::string full_move_counter = fen_tokens.size() > 4 ? fen_tokens[5] : "1";

    side = (player == "w") ? WHITE : BLACK;

    auto pos = static_cast<Square>(56);

    // Parsing the main 8x8 board part while adding appropriate padding
    for (char c : position) {
        if (c == '/' ) {
            pos = static_cast<Square>(pos - 16);
        } else if (std::isdigit(c)) {

            for (int empty_amt = 0; empty_amt < c - '0'; empty_amt++) {
                board[pos] = EMPTY;
                pos = static_cast<Square>(pos + 1);
            }

        }
        else if (std::isalpha(c)) {

            //Piece piece = piece_to_num(c);
            //place_piece(piece, pos);

            pos = static_cast<Square>(pos + 1);

        }
    }

    i32 castle_ability_bits = 0;
    for (char c : castling) {

        if (c == 'K') castle_ability_bits |= 1;
        else if (c == 'Q') castle_ability_bits |= 2;
        else if (c == 'k') castle_ability_bits |= 4;
        else if (c == 'q') castle_ability_bits |= 8;

    }

	/*
    if (en_passant.size() > 1) {
        auto square = static_cast<Square>((8 - (en_passant[1] - '0')) * 8 + en_passant[0] - 'a');
        ep_square = square;
    } else {
        ep_square = NO_SQUARE;
    }
    */
}

std::ostream& operator << (std::ostream& os, const Position& p) {
	const char* s = "   +---+---+---+---+---+---+---+---+\n";
	const char* t = "     A   B   C   D   E   F   G   H\n";
	os << t;
	for (int i = 56; i >= 0; i -= 8) {
		os << s << " " << i / 8 + 1 << " ";
		for (int j = 0; j < 8; j++)
			os << "| " << PIECE_MATCHER[p.board[i + j]] << " ";
		os << "| " << i / 8 + 1 << "\n";
	}
	os << s;
	os << t << "\n";

	//os << "FEN: " << p.fen() << "\n";
	//os << "Hash: 0x" << std::hex << p.hash << std::dec << "\n";

	return os;
}

void Position::reset() {
	hash_history.clear();
	state_history.clear();

	pieces.fill(0);
	board.fill(EMPTY);

	side = WHITE;
	hash_key = 0;
	game_ply = 0;
}

std::string Position::fen() {
	return "incomplete";
}

template<Color color>
void Position::play(Move &move) {

}

template<Color color>
void Position::undo(Move &move) {

}

template void Position::play<WHITE>(Move &move);
template void Position::play<BLACK>(Move &move);
template void Position::undo<WHITE>(Move &move);
template void Position::undo<BLACK>(Move &move);