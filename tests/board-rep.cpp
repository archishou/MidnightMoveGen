#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "lib/doctests.h"
#include "../src/position.h"

TEST_SUITE_BEGIN("board-rep");

TEST_CASE("pawn-attacks") {
	Position p(START_FEN);
	std::cout << p << std::endl;
}

TEST_SUITE_END();