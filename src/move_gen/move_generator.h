#pragma once

#include "types/types.h"
#include "../board/position.h"
#include "../utils/stack.h"

template<Color color, MoveGenerationType move_gen_type>
class MoveList {
private:
	Stack<Move, 218> move_list{};

	consteval Bitboard generate_danger();
public:
	explicit MoveList(Position& board);

	[[nodiscard]] inline auto begin() const { return move_list.begin(); }
	[[nodiscard]] inline auto end() const { return move_list.end(); }
	[[nodiscard]] inline auto size() const { return move_list.size(); }
};

template<Color color, MoveGenerationType move_gen_type>
consteval Bitboard MoveList<color, move_gen_type>::generate_danger() {
	return 0;
}

template<Color color, MoveGenerationType move_gen_type>
MoveList<color, move_gen_type>::MoveList(Position &board) {

	const Bitboard us_bb = board.occupancy<color>();
	const Bitboard them_bb = board.occupancy<~color>();
	const Bitboard all = us_bb | them_bb;

	const Square our_king = bsf(board.occupancy<color, KING>());
	const Square their_king = bsf(board.occupancy<color, KING>());

	const Bitboard our_diag_sliders = board.diagonal_sliders<color>();
	const Bitboard their_diag_sliders = board.diagonal_sliders<~color>();

	const Bitboard our_orth_sliders = board.orthogonal_sliders<color>();
	const Bitboard their_orth_sliders = board.orthogonal_sliders<~color>();
}
