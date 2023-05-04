//
// Created by Alex Tian on 12/2/2022.
//

#include <stdexcept>
#include <iostream>
#include "position.h"
#include "utils/helpers.h"
#include "types/bitboard.h"
#include "constants/misc_constants.h"
#include "constants/zobrist_constants.h"

void Position::remove_piece(Square square) {
	state_history.top().hash ^= ZOBRIST_PIECE_SQUARE[piece_at(square)][square];
	pieces[piece_at(square)] &= ~from_square(square);
	board[square] = NO_PIECE;
}

void Position::place_piece(Piece piece, Square square) {
	pieces[piece] |= (1ULL << square);
	board[square] = piece;
	state_history.top().hash ^= ZOBRIST_PIECE_SQUARE[piece][square];
}

void Position::move_piece(Piece piece, Square to, Square from) {
	remove_piece(from);
	place_piece(piece, to);
}

void Position::set_fen(const std::string& fen_string) {
	reset();

	// Push empty state to state history.
	state_history.push({});

	std::vector<std::string> fen_tokens = split(fen_string, " ");

	if (fen_tokens.size() < 4) {
		throw std::invalid_argument("Fen is missing fields. ");
	}

	const std::string position = fen_tokens[0];
	const std::string player = fen_tokens[1];
	const std::string castling = fen_tokens[2];
	const std::string en_passant = fen_tokens[3];

	const std::string half_move_clock = fen_tokens.size() > 4 ? fen_tokens[4] : "0";
	const std::string full_move_counter = fen_tokens.size() > 4 ? fen_tokens[5] : "1";

	side = player == "w" ? WHITE : BLACK;

	Square square = a8;

	for (char ch : position) {
		if (isdigit(ch)) square += std::stoi(std::string(1, ch)) * EAST;
		else if (ch == '/') square += SOUTH_SOUTH;
		else place_piece(piece_from_char(ch), square++);
	}

	state_history.top().from_to = PositionState::ALL_CASTLING_MASK;
	for (char c : castling) {
		if (c == 'K') 		state_history.top().from_to &= ~PositionState::WHITE_OO_MASK;
		else if (c == 'Q') 	state_history.top().from_to &= ~PositionState::WHITE_OOO_MASK;
		else if (c == 'k') 	state_history.top().from_to &= ~PositionState::BLACK_OO_MASK;
		else if (c == 'q') 	state_history.top().from_to &= ~PositionState::BLACK_OOO_MASK;
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
	const std::string s = "   +---+---+---+---+---+---+---+---+\n";
	const std::string t = "     A   B   C   D   E   F   G   H\n";
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
	state_history.clear();

	pieces.fill(0);
	board.fill(NO_PIECE);

	side = WHITE;
}

std::string Position::fen() {
	return "incomplete";
}

Position::Position(const std::string& fen) {
	set_fen(fen);
}


template<Color color>
void Position::play(Move &move) {
	PositionState next_state = {};
	next_state.from_to = state_history.peek().from_to | move.from() | move.to();
	next_state.captured = piece_at(move.to());
	next_state.hash = state_history.peek().hash;
	next_state.fifty_move_rule = state_history.peek().fifty_move_rule + 1;
	next_state.ep_square = NO_SQUARE;

	if (move.is_capture() || type_of(piece_at(move.from())) == PAWN)
		next_state.fifty_move_rule = 0;

	side = ~side;
}

template<Color color>
void Position::undo(Move &move) {
	PositionState old_state = state_history.pop();
}

template void Position::play<WHITE>(Move &move);
template void Position::play<BLACK>(Move &move);
template void Position::undo<WHITE>(Move &move);
template void Position::undo<BLACK>(Move &move);