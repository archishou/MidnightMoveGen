#include "lib/doctests.h"
#include "../src/board/position.h"
#include "../src/move_gen/move_generator.h"
#include "iostream"
#include "fstream"
#include "../src/utils/helpers.h"

template<Color Us>
u64 perft_node_count(Position& p, unsigned int depth) {
	unsigned long long nodes = 0;

	MoveList<Us, ALL> list(p);
	if (depth == 1) return (unsigned long long) list.size();
	for (Move move : list) {
		p.play<Us>(move);
		nodes += perft_node_count<~Us>(p, depth - 1);
		p.undo<Us>(move);
	}
	return nodes;
}

u64 test_perft_node_count(const std::string& fen, int depth) {
	Position p(fen);
	if (p.side == WHITE) {
		return perft_node_count<WHITE>(p, depth);
	} else {
		return perft_node_count<BLACK>(p, depth);
	}
}

TEST_SUITE_BEGIN("perft-final");

TEST_CASE("PerftDepthSixDefaultFen") {
	CHECK_EQ(test_perft_node_count(START_FEN, 6), 119060324);
}

TEST_CASE("PerftDepthFiveKiwipete") {
	CHECK_EQ(test_perft_node_count(KIWIPETE_FEN, 5), 193690690);
}

TEST_CASE("PerftTestPosition") {
	CHECK_EQ(test_perft_node_count("rn2kbnr/pp2pppp/2p5/8/5B2/N2P1B1P/PP3PP1/R4RK1 w kq - 0 13", 5), 18292958);
}

TEST_CASE("PerftTestPosition2") {
	CHECK_EQ(test_perft_node_count("8/8/8/3p4/4pn1N/6p1/8/5K1k w - - 10 73", 8), 24490963);
}

TEST_CASE("PerftTestPosition5") {
	CHECK_EQ(test_perft_node_count("rnb1kbnr/ppp1pppp/4q3/3pP3/8/4K3/PPPP1PPP/RNBQ1BNR w - d6 0 1", 1), 34);
}

TEST_CASE("PerftTestPosition6") {
	CHECK_EQ(test_perft_node_count("rnb1kbnr/ppp1pppp/4q3/3pP3/8/5K2/PPPP1PPP/RNBQ1BNR w - d6 0 1", 1), 28);
}

TEST_CASE("PerftTestPosition7") {
	CHECK_EQ(test_perft_node_count("rnb1kbnr/ppq1pppp/p7/3pP3/8/6K1/PPPP1PPP/RNBQ1BNR w - d6 0 1", 1), 31);
}

TEST_CASE("PerftTestPosition3") {
	CHECK_EQ(test_perft_node_count("8/8/8/3p4/5n2/4p3/6pk/4KN2 b - - 3 76", 1), 7);
}

TEST_CASE("PerftTestPositionKnightCheck"){
	CHECK_EQ(test_perft_node_count("5n2/3KPk2/8/3p1N2/3P4/8/8/8 w - - 17 102", 8), 80433958);
}

TEST_CASE("perft-all") {
	std::string perft_file_path = "./tests/perft_results.txt";
	std::ifstream input_file(perft_file_path);
	std::string input_line;

	auto start_time = std::chrono::high_resolution_clock::now();

	unsigned long long total_nodes = 0;
	while (std::getline(input_file, input_line)) {
		std::vector<std::string> split_perft = split(input_line, ";");
		std::string fen = split_perft[0];
		for (usize i = 1; i < split_perft.size(); i++) {
			std::string expected = split_perft[i];
			int depth = static_cast<i32>(i);
			int expected_node_count = std::stoi(split(expected, " ")[2]);
			CHECK_EQ(test_perft_node_count(fen, depth), expected_node_count);
			total_nodes += expected_node_count;
		}
	}

	auto end_time = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end_time - start_time;
	double seconds_elapsed = diff.count();
	auto elap = static_cast<int>(seconds_elapsed * static_cast<int>(1000));

	std::cout << "Total Nodes: " << total_nodes << std::endl;
	std::cout << "Elapsed Time(ms): " << elap << std::endl;
	std::cout << "NPS: " << (total_nodes * 1000) / elap << std::endl;
	input_file.close();
}


TEST_SUITE_END();