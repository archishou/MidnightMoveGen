#include "lib/doctests.h"
#include "../src/board/position.h"
#include "../src/move_gen/move_generator.h"
#include "iostream"

TEST_SUITE_BEGIN("perft");

template<Color Us>
unsigned long long perft(Position& p, unsigned int depth) {
	unsigned long long nodes = 0;

	if (depth == 0) return 1;

	MoveList<Us, ALL> list(p);

	for (Move move : list) {
		p.play<Us>(move);
		nodes += perft<~Us>(p, depth - 1);
		p.undo<Us>(move);
	}

	return nodes;
}

template<Color Us>
unsigned long long split_perft(Position& p, unsigned int depth) {
	unsigned long long nodes = 0, pf{};

	MoveList<Us, ALL> list(p);

	for (Move move : list) {
		std::cout << move;
		p.play<Us>(move);
		pf = perft<~Us>(p, depth - 1);
		std::cout << ": " << pf << " moves " << p.fen() << std::endl;
		nodes += pf;
		p.undo<Us>(move);
	}

	return nodes;
}

TEST_CASE("startpos-perft") {
	Position board{START_FEN};

	/*
	board.play<WHITE>(Move(a2, a4, DOUBLE_PUSH));
	board.play<BLACK>(Move(b8, a6, QUIET));
	board.play<WHITE>(Move(a4, a5, QUIET));
	board.play<BLACK>(Move(b7, b5, DOUBLE_PUSH));
	*/

	Bitboard total_moves = split_perft<WHITE>(board, 6);
	std::cout << "total moves: " << total_moves << std::endl;
}

TEST_SUITE_END();