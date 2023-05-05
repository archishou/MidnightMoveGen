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

class Position;

class PositionState {
	friend Position;
private:
	static constexpr Bitboard WHITE_OO_MASK		= 0x90;
	static constexpr Bitboard WHITE_OOO_MASK	= 0x11;

	static constexpr Bitboard BLACK_OO_MASK		= 0x9000000000000000;
	static constexpr Bitboard BLACK_OOO_MASK	= 0x1100000000000000;

	static constexpr Bitboard NO_CASTLING_MASK = 0x9100000000000091;

	Bitboard from_to{};
	Piece captured{};
	Square ep_square = NO_SQUARE;
	u16 fifty_move_rule{};
	ZobristHash hash{};

public:
	PositionState() = default;
	~PositionState() = default;
};

class Position {
public:
//private: commented out for debugging
	Color side = WHITE;

	std::array<Bitboard, NPIECES> pieces{};
	std::array<Piece, NSQUARES> board{};

	static constexpr i16 POSITION_STATE_SIZE = 1000;

	Stack<PositionState, POSITION_STATE_SIZE> state_history{};

	static constexpr bool ENABLE_HASH_UPDATE = true;
	static constexpr bool DISABLE_HASH_UPDATE = false;

	template<bool update_hash>
	void place_piece(Piece piece, Square square);

	template<bool update_hash>
	void remove_piece(Square square);

	template<bool update_hash>
	void move_piece(Square from, Square to);

	void reset();

	[[nodiscard]] u8 castling_state(Bitboard from_to) const;

//public: commented out for debugging
	Position() = default;
	explicit Position(const std::string& fen);

	[[nodiscard]] inline Piece piece_at(Square square) const { return board[square]; }

	[[nodiscard]] inline u16 fifty_move_rule() const { return state_history.peek().fifty_move_rule; }
	[[nodiscard]] inline Square ep_square() const { return state_history.peek().ep_square; }
	[[nodiscard]] inline ZobristHash hash() const { return state_history.peek().hash; }

	void set_fen(const std::string& fen);
	[[nodiscard]] std::string fen() const;
	friend std::ostream& operator<<(std::ostream& os, const Position& p);

	template<Color color>
	void play(Move move);

	template<Color color>
	void undo(Move move);
};
