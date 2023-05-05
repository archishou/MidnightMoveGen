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

TEST_CASE("play-undo-castling") {
	Position p(START_FEN);

	Move m1 = Move(e2, e4, DOUBLE_PUSH);
	std::string m1_fen = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1";

	Move m2 = Move(e7, e5, DOUBLE_PUSH);
	std::string m2_fen = "rnbqkbnr/pppp1ppp/8/4p3/4P3/8/PPPP1PPP/RNBQKBNR w KQkq e6 0 1";

	Move m3 = Move(f1, c4, QUIET);
	std::string m3_fen = "rnbqkbnr/pppp1ppp/8/4p3/2B1P3/8/PPPP1PPP/RNBQK1NR b KQkq - 0 1";

	Move m4 = Move(f8, c5, QUIET);
	std::string m4_fen = "rnbqk1nr/pppp1ppp/8/2b1p3/2B1P3/8/PPPP1PPP/RNBQK1NR w KQkq - 0 1";

	Move m5 = Move(g1, f3, QUIET);
	std::string m5_fen = "rnbqk1nr/pppp1ppp/8/2b1p3/2B1P3/5N2/PPPP1PPP/RNBQK2R b KQkq - 0 1";

	Move m6 = Move(g8, f6, QUIET);
	std::string m6_fen = "rnbqk2r/pppp1ppp/5n2/2b1p3/2B1P3/5N2/PPPP1PPP/RNBQK2R w KQkq - 0 1";

	Move m7 = Move(e1, g1, OO);
	std::string m7_fen = "rnbqk2r/pppp1ppp/5n2/2b1p3/2B1P3/5N2/PPPP1PPP/RNBQ1RK1 b kq - 0 1";

	p.play<WHITE>(m1);
	CHECK_EQ(p.fen(), m1_fen);

	p.play<BLACK>(m2);
	CHECK_EQ(p.fen(), m2_fen);

	p.play<WHITE>(m3);
	CHECK_EQ(p.fen(), m3_fen);

	p.play<BLACK>(m4);
	CHECK_EQ(p.fen(), m4_fen);

	p.play<WHITE>(m5);
	CHECK_EQ(p.fen(), m5_fen);

	p.play<BLACK>(m6);
	CHECK_EQ(p.fen(), m6_fen);

	p.play<WHITE>(m7);
	CHECK_EQ(p.fen(), m7_fen);
	std::cout << p << std::endl;
}

TEST_SUITE_END();