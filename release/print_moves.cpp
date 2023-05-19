//
// Created by Archishmaan Peyyety on 5/18/23.
//

#include "move_gen.h"

int main() {
	Midnight::Position board{Midnight::START_FEN};
	Midnight::MoveList<Midnight::WHITE, Midnight::MoveGenerationType::ALL> move_list(board);

	for (auto move : move_list) {
		std::cout << move << std::endl;
	}
}