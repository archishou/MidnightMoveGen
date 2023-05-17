//
// Created by Alexander Tian on 4/26/23.
//

#pragma once
#include "../types/bitboard.h"
#include "../../types.h"
#include "../types/piece.h"

inline const string START_FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
inline const string INITIAL_BOARD_FEN = START_FEN;
inline const string KIWIPETE_FEN = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1";
inline const string TALKCHESS_FEN = "rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8";

constexpr char PIECE_MATCHER[NPIECES] = {'P', 'N', 'B', 'R', 'Q', 'K', '-', '-', 'p', 'n', 'b', 'r', 'q', 'k', '-'};