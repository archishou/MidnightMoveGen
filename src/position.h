//
// Created by Alex Tian on 12/2/2022.
//
#pragma once
#include <string>
#include "constants/misc_constants.h"
#include "types.h"
#include "types/bitboard.h"
#include "constants/misc_constants.h"
#include "types/move.h"
#include "utils/stack.h"
#include "types/board_rep_types.h"

class PositionState {
private:
	static constexpr Bitboard WHITE_OO_MASK		= 0x90;
	static constexpr Bitboard WHITE_OOO_MASK	= 0x11;

	static constexpr Bitboard BLACK_OO_MASK		= 0x9000000000000000;
	static constexpr Bitboard BLACK_OOO_MASK	= 0x1100000000000000;

	static constexpr Bitboard ALL_CASTLING_MASK = 0x9100000000000091;

public:
	PositionState() = default;
	~PositionState() = default;

	Bitboard from_to{};
	Piece captured{};
	Square ep_square{};
	u16 fifty_move_rule{};
	ZobristHash hash{};
};

class Position {
private:
	Color side = WHITE;
	i32 game_ply{};

	std::array<Bitboard, NPIECES> pieces{};

	static constexpr i16 POSITION_STATE_SIZE = 1000;

	Stack<PositionState, POSITION_STATE_SIZE> state_history{};

	void remove_piece(Piece piece, Square square);
	void place_piece(Piece piece, Square square);

	void reset();

public:

	std::array<Piece, NSQUARES> board{};
    Position() = default;

	[[nodiscard]] inline u16 fifty_move_rule() const { return state_history.peek().fifty_move_rule; }
	[[nodiscard]] inline Square ep_square() const { return state_history.peek().ep_square; }
	[[nodiscard]] inline ZobristHash hash() const { return state_history.peek().hash; }

    void set_fen(const std::string& fen);
	std::string fen();

	template<Color color>
	void play(Move& move);

	template<Color color>
	void undo(Move& move);

	friend std::ostream& operator<<(std::ostream& os, const Position& p);
};
