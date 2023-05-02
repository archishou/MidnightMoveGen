#pragma once
#include <cstdint>
#include "types.h"

using MoveType = u8;

MoveType QUIET		= 0b0000;
MoveType OO			= 0b0001;
MoveType OOO		= 0b0010;

// Captures have the 4th bit set.
MoveType CAPTURE	= 0b1000;
MoveType ENPASSANT	= 0b1001;

// Promotions have the 3rd bit set.
MoveType PR_KNIGHT	= 0b0100;
MoveType PR_BISHOP	= 0b0101;
MoveType PR_ROOK	= 0b0110;
MoveType PR_QUEEN	= 0b0111;

class Move {
private:
	// Bits are arranged as follows
	// | 1 bits for type | 6 bits for from | 6 bits for to
	uint16_t move;

	static constexpr u8 TO_SHIFT = 0;
	static constexpr u8 FROM_SHIFT = 6;
	static constexpr u8 TYPE_SHIFT = 12;

public:
	inline Move() : move(0) {}

	inline explicit Move(uint16_t m) { move = m; }

	inline Move(Square from, Square to) : move(0) {
		move = (from << 6) | to;
	}

	inline Move(Square from, Square to, MoveType type) : move(0) {
		move = (type << TYPE_SHIFT) | (from << FROM_SHIFT) | to << TO_SHIFT;
	}

	[[nodiscard]] inline Square to() const { return Square(move & 0x3f); }
	[[nodiscard]] inline Square from() const { return Square((move >> FROM_SHIFT) & 0x3f); }
	[[nodiscard]] inline MoveType type() const { return (move >> TYPE_SHIFT) & 0xf; }

	[[nodiscard]] inline bool is_capture() const { return (move >> TYPE_SHIFT) & 0b1000; }
	[[nodiscard]] inline bool is_promotion() const { return (move >> TYPE_SHIFT) & 0b0100; }
	[[nodiscard]] inline bool is_quiet() const { return !is_capture() && !is_promotion(); }

	bool operator==(Move a) const { return move == a.move; }
	bool operator!=(Move a) const { return move != a.move; }
};

const Move EMPTY_MOVE = Move();
