#ifndef MOVE_H
#define MOVE_H

#include <cstdint>
#include "types.h"

enum MoveType : uint8_t {
	MOVE_TYPE_NORMAL	= 0b0000,
	MOVE_TYPE_EP		= 0b0001,
	MOVE_TYPE_CASTLE	= 0b0010,
	MOVE_TYPE_PROMOTION	= 0b0011,
};

enum PromotionType : uint8_t {
	PROMOTION_KNIGHT	= 0b0000,
	PROMOTION_BISHOP	= 0b0001,
	PROMOTION_ROOK		= 0b0010,
	PROMOTION_QUEEN		= 0b0011,
};

class Move {
private:
	// Bits are arranged as follows
	// | 2 bits for type | 2 bits for promotion piece | 6 bits for from | 6 bits for to
	uint16_t move;
public:
	inline Move() : move(0) {}

	inline explicit Move(uint16_t m) { move = m; }

	inline Move(Square from, Square to) : move(0) {
		move = (from << 6) | to;
	}

	inline Move(Square from, Square to, MoveType type, PromotionType promotion_type) : move(0) {
		move = promotion_type << 14 | (type << 12) | (from << 6) | to;
	}

	[[nodiscard]] inline Square to() const { return Square(move & 0x3f); }
	[[nodiscard]] inline Square from() const { return Square((move >> 6) & 0x3f); }
	[[nodiscard]] inline MoveType type() const { return MoveType((move >> 12) & 0xf); }
	[[nodiscard]] inline PromotionType promotion_piece() const { return PromotionType((move >> 14) & 0xf); }

	bool operator==(Move a) const { return move == a.move; }
	bool operator!=(Move a) const { return move != a.move; }
};

const Move EMPTY_MOVE = Move();


#endif // MOVE_H