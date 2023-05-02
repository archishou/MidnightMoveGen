//
// Created by Alex Tian on 12/2/2022.
//
#pragma once
#include <string>
#include "constants.h"
#include "types.h"
#include "bitboard.h"
#include "constants.h"
#include "move.h"
#include "stack.h"

class PositionState {
public:
	PositionState() = default;

private:
	Bitboard from_to{};
	Piece captured{};
	Square ep_square{};
	u8 fifty_move_rule{};
};

class Position {

public:

    Position() = default;

    Bitboard pieces[NPIECES]{};

    Piece board[NSQUARES]{};

    Color side = WHITE;

    Square ep_square = NO_SQUARE;
    ZobristHash hash_key = 0;
	i32 game_ply{};

	Stack<PositionState, 1000> state_history{};

    void remove_piece(Piece piece, Square square);
    void place_piece(Piece piece, Square square);

    void set_fen(const std::string& fen);

	void play(Move& move);
	void undo(Move& move);

	friend std::ostream& operator<<(std::ostream& os, const Position& p);
};
