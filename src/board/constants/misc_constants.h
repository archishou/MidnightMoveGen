//
// Created by Alexander Tian on 4/26/23.
//

#pragma once
#include "../types/bitboard.h"
#include "../../types.h"
#include "../types/piece.h"

const std::string START_FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
//const std::string KIWIPETE_FEN = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1";

constexpr char PIECE_MATCHER[NPIECES] = {'P', 'N', 'B', 'R', 'Q', 'K', '-', '-', 'p', 'n', 'b', 'r', 'q', 'k', '-'};