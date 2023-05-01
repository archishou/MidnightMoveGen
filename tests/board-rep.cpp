#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "lib/doctests.h"
#include "../position.h"

TEST_SUITE_BEGIN("board-rep");

TEST_CASE("pawn-attacks") {
	Position p;
	print_bitboard(from_square(a1));
}

TEST_SUITE_END();