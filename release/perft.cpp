//
// Created by Archishmaan Peyyety on 5/18/23.
//
#include "move_gen.h"
#include <string>
#include <cstdint>

using u64 = std::uint64_t;
using i32 = std::int32_t;

template<Midnight::Color Us>
u64 perft_node_count(Midnight::Position& p, i32 depth) {
	u64 nodes = 0;

	Midnight::MoveList<Us, Midnight::MoveGenerationType::ALL> list(p);
	if (depth == 1) return list.size();
	for (auto move : list) {
		p.play<Us>(move);
		nodes += perft_node_count<~Us>(p, depth - 1);
		p.undo<Us>(move);
	}
	return nodes;
}

u64 test_perft_node_count(const std::string& fen, i32 depth) {
	Midnight::Position p(fen);
	if (p.turn() == Midnight::WHITE) {
		return perft_node_count<Midnight::WHITE>(p, depth);
	} else {
		return perft_node_count<Midnight::BLACK>(p, depth);
	}
}

int main() {
	std::cout << test_perft_node_count(Midnight::START_FEN, 2);
}
