//
// Created by Archishmaan Peyyety on 5/16/23.
//
#include "lib/doctests.h"
#include "iostream"
#include "../src/board/position.h"

TEST_SUITE_BEGIN("hash");

TEST_CASE("side-to-move") {
	Position from_fen("rnbqkbnr/ppppp1pp/8/5p2/5P2/2N5/PPPPP1PP/R1BQKBNR b KQkq - 1 2");

	Position board_1(START_FEN);
	board_1.play<WHITE>(Move(f2, f4, DOUBLE_PUSH));
	board_1.play<BLACK>(Move(f7, f5, DOUBLE_PUSH));
	board_1.play<WHITE>(Move(b1, c3, QUIET));

	Position board_2(START_FEN);
	board_2.play<WHITE>(Move(f2, f3, QUIET));
	board_2.play<BLACK>(Move(f7, f6, QUIET));
	board_2.play<WHITE>(Move(f3, f4, QUIET));
	board_2.play<BLACK>(Move(f6, f5, QUIET));
	board_2.play<WHITE>(Move(b1, c3, QUIET));

	CHECK_EQ(from_fen.hash(), board_1.hash());
	CHECK_EQ(board_1.hash(), board_2.hash());
}

TEST_CASE("castling") {
	Position from_fen("rnbqk2r/pppppp1p/5n2/2b3p1/2B3P1/5N2/PPPPPP1P/RNBQ1RK1 b kq - 0 3");

	Position board_1("rnbqk2r/pppppppp/5n2/2b5/2B5/5N2/PPPPPPPP/RNBQK2R w KQkq - 0 1");
	Position board_2("rnbqk2r/pppppppp/5n2/2b5/2B5/5N2/PPPPPPPP/RNBQK2R w KQkq - 0 1");

	board_1.play<WHITE>(Move(g2, g4, DOUBLE_PUSH));
	board_1.play<BLACK>(Move(g7, g5, DOUBLE_PUSH));
	board_1.play<WHITE>(Move(e1, g1, OO));

	board_2.play<WHITE>(Move(e1, g1, OO));
	board_2.play<BLACK>(Move(g7, g6, QUIET));
	board_2.play<WHITE>(Move(g2, g3, QUIET));
	board_2.play<BLACK>(Move(g6, g5, QUIET));
	board_2.play<WHITE>(Move(g3, g4, QUIET));
	CHECK_EQ(from_fen.hash(), board_1.hash());
	CHECK_EQ(board_1.hash(), board_2.hash());
}

TEST_CASE("en-passant") {
	Position from_fen("rnbqkbnr/pppp1pp1/8/3Pp2p/8/8/PPP1PPPP/RNBQKBNR w KQkq e6 0 4");

	Position board_1(START_FEN);
	Position board_2(START_FEN);

	board_1.play<WHITE>(Move(d2, d3, QUIET));
	board_1.play<BLACK>(Move(h7, h6, QUIET));
	board_1.play<WHITE>(Move(d3, d4, QUIET));
	board_1.play<BLACK>(Move(h6, h5, QUIET));
	board_1.play<WHITE>(Move(d4, d5, QUIET));
	board_1.play<BLACK>(Move(e7, e5, DOUBLE_PUSH));

	board_2.play<WHITE>(Move(d2, d4, DOUBLE_PUSH));
	board_2.play<BLACK>(Move(h7, h5, DOUBLE_PUSH));
	board_2.play<WHITE>(Move(d4, d5, QUIET));
	board_2.play<BLACK>(Move(e7, e5, DOUBLE_PUSH));

	CHECK_EQ(from_fen.hash(), board_1.hash());
	CHECK_EQ(board_1.hash(), board_2.hash());
}

TEST_SUITE_END();