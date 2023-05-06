#pragma once

#include "../types/board_rep_types.h"
#include "types.h"
#include "../board/position.h"

template<Color color, MoveGenerationType move_gen_type>
class MoveList {
private:
	Stack<Move, 218> move_list{};
public:
	explicit MoveList(Position& board);

	[[nodiscard]] inline auto begin() const { return move_list.begin(); }
	[[nodiscard]] inline auto end() const { return move_list.end(); }
	[[nodiscard]] inline auto size() const { return move_list.size(); }
};

template<Color color, MoveGenerationType move_gen_type>
MoveList<color, move_gen_type>::MoveList(Position &board) {

}
