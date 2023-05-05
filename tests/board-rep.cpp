#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "lib/doctests.h"
#include "../src/position.h"

TEST_SUITE_BEGIN("board-rep");
static constexpr ZobristHash START_POS_HASH = 0x2278897016d03aa6;

TEST_CASE("play-undo-ep") {

	Position p(START_FEN);

	CHECK_EQ(p.hash(), START_POS_HASH);
	CHECK_EQ(p.fen(), START_FEN);

	Move move_1 = Move(e2, e4, DOUBLE_PUSH);
	std::string fen_1 = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1";

	Move move_2 = Move(h7, h6, QUIET);
	std::string fen_2 = "rnbqkbnr/ppppppp1/7p/8/4P3/8/PPPP1PPP/RNBQKBNR w KQkq - 0 1";

	Move move_3 = Move(e4, e5, QUIET);
	std::string fen_3 = "rnbqkbnr/ppppppp1/7p/4P3/8/8/PPPP1PPP/RNBQKBNR b KQkq - 0 1";

	Move move_4 = Move(d7, d5, DOUBLE_PUSH);
	std::string fen_4 = "rnbqkbnr/ppp1ppp1/7p/3pP3/8/8/PPPP1PPP/RNBQKBNR w KQkq d6 0 1";

	Move move_5 = Move(e5, d6, ENPASSANT);
	std::string fen_5 = "rnbqkbnr/ppp1ppp1/3P3p/8/8/8/PPPP1PPP/RNBQKBNR b KQkq - 0 1";

	p.play<WHITE>(move_1);
	CHECK_EQ(p.fen(), fen_1);

	p.play<BLACK>(move_2);
	CHECK_EQ(p.fen(), fen_2);

	p.play<WHITE>(move_3);
	CHECK_EQ(p.fen(), fen_3);

	p.play<BLACK>(move_4);
	CHECK_EQ(p.fen(), fen_4);

	p.play<WHITE>(move_5);
	CHECK_EQ(p.fen(), fen_5);
	p.undo<WHITE>(move_5);

	CHECK_EQ(p.fen(), fen_4);
	p.undo<BLACK>(move_4);

	CHECK_EQ(p.fen(), fen_3);
	p.undo<WHITE>(move_3);

	CHECK_EQ(p.fen(), fen_2);
	p.undo<BLACK>(move_2);

	CHECK_EQ(p.fen(), fen_1);
	p.undo<WHITE>(move_1);

	CHECK_EQ(p.hash(), START_POS_HASH);
	CHECK_EQ(p.fen(), START_FEN);
}

TEST_SUITE_END();