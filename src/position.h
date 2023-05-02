//
// Created by Alex Tian on 12/2/2022.
//
#pragma once
#include <string>
#include "constants/misc_constants.h"
#include "types.h"
#include "bitboard.h"
#include "constants/misc_constants.h"
#include "move.h"
#include "utils/stack.h"

class PositionState {
public:
	PositionState() = default;
	~PositionState() = default;

	Bitboard from_to{};
	Piece captured{};
	Square ep_square{};
	u16 fifty_move_rule{};
};

class Position {
private:
	static constexpr i16 POSITION_STATE_SIZE = 1000;

	Stack<PositionState, POSITION_STATE_SIZE> state_history{};

	void remove_piece(Piece piece, Square square);
	void place_piece(Piece piece, Square square);

	void reset();

public:

    Position() = default;

	std::array<Bitboard, NPIECES> pieces{};
	std::array<Piece, NSQUARES> board{};

    Color side = WHITE;
    ZobristHash hash_key = 0;
	i32 game_ply{};

	Stack<ZobristHash, POSITION_STATE_SIZE> hash_history{};
	[[nodiscard]] inline u16 fifty_move_rule() const { return state_history.peek().fifty_move_rule; }
	[[nodiscard]] inline Square ep_square() const { return state_history.peek().ep_square; }

    void set_fen(const std::string& fen);
	std::string fen();

	template<Color color>
	void play(Move& move);

	template<Color color>
	void undo(Move& move);

	friend std::ostream& operator<<(std::ostream& os, const Position& p);
};
