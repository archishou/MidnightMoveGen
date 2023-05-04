#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "lib/doctests.h"
#include "../src/position.h"

TEST_SUITE_BEGIN("board-rep");

TEST_CASE("pawn-attacks") {
	Position p;
	p.set_fen(START_FEN);
	std::cout << " hi" << std::endl;
	std::cout << p << std::endl;
}

TEST_SUITE_END();