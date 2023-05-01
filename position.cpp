//
// Created by Alex Tian on 12/2/2022.
//

#include <stdexcept>
#include <iostream>
#include <bitset>
#include "position.h"
#include "useful.h"
#include "bitboard.h"
#include "tables.h"

BITBOARD Position::get_pieces(Piece piece) {
    return pieces[piece];
}

BITBOARD Position::get_pieces(PieceType piece, Color color) {
    return pieces[piece + color * 6];
}

BITBOARD Position::get_our_pieces() {
    return get_pieces(PAWN, side)	|
           get_pieces(KNIGHT, side)	|
           get_pieces(BISHOP, side)	|
           get_pieces(ROOK, side)	|
           get_pieces(QUEEN, side)	|
           get_pieces(KING, side);
}

BITBOARD Position::get_opp_pieces() {
    return get_pieces(PAWN, ~side)	 |
           get_pieces(KNIGHT, ~side) |
           get_pieces(BISHOP, ~side) |
           get_pieces(ROOK, ~side)	 |
           get_pieces(QUEEN, ~side)	 |
           get_pieces(KING, ~side);
}

BITBOARD Position::get_all_pieces() {
    return get_our_pieces() | get_opp_pieces();
}

Piece Position::get_piece_standard(Square square) {
    return board[square];
}

void Position::remove_piece(Piece piece, Square square) {
    pieces[piece] &= ~(1ULL << square);
    board[square] = EMPTY;
}

void Position::place_piece(Piece piece, Square square) {
    pieces[piece] |= (1ULL << square);
    board[square] = piece;
}

void Position::set_fen(const std::string& fen_string) {

    std::vector<std::string> fen_tokens = split(fen_string, ' ');

    if (fen_tokens.size() < 4) {
        throw std::invalid_argument( "Fen is incorrect" );
    }

    const std::string position = fen_tokens[0];
    const std::string player = fen_tokens[1];
    const std::string castling = fen_tokens[2];
    const std::string en_passant = fen_tokens[3];

    const std::string half_move_clock = fen_tokens.size() > 4 ? fen_tokens[4] : "0";
    const std::string full_move_counter = fen_tokens.size() > 4 ? fen_tokens[5] : "1";

    side = (player == "w") ? WHITE : BLACK;

    for (int piece = WHITE_PAWN; piece != EMPTY; piece++) {
        pieces[piece] = 0ULL;
    }

    auto pos = static_cast<Square>(56);

    // Parsing the main 8x8 board part while adding appropriate padding
    for (char c : position) {
        if (c == '/' ) {
            pos = static_cast<Square>(pos - 16);
        } else if (std::isdigit(c)) {

            for (int empty_amt = 0; empty_amt < c - '0'; empty_amt++) {
                board[pos] = EMPTY;
                pos = static_cast<Square>(pos + 1);
            }

        }
        else if (std::isalpha(c)) {

            Piece piece = piece_to_num(c);
            place_piece(piece, pos);

            pos = static_cast<Square>(pos + 1);

        }
    }

    castle_ability_bits = 0;
    for (char c : castling) {

        if (c == 'K') castle_ability_bits |= 1;
        else if (c == 'Q') castle_ability_bits |= 2;
        else if (c == 'k') castle_ability_bits |= 4;
        else if (c == 'q') castle_ability_bits |= 8;

    }

    if (en_passant.size() > 1) {
        auto square = static_cast<Square>((8 - (en_passant[1] - '0')) * 8 + en_passant[0] - 'a');
        ep_square = square;
    }
    else {
        ep_square = NO_SQUARE;
    }
}

std::ostream& operator << (std::ostream& os, const Position& p) {
    std::string new_board;

    auto pos = static_cast<Square>(56);
    for (int i = 0; i < 64; i++) {
        if (i != 0 && i % 8 == 0) {
            new_board += '\n';
            pos = static_cast<Square>(pos - 16);
        }

        Piece piece = p.board[pos];
        pos = static_cast<Square>(pos + 1);

        if (piece == EMPTY) {
            new_board += ". ";
            continue;
        }

        //assert((pieces[piece] & (1ULL << MAILBOX_TO_STANDARD[pos]) >> MAILBOX_TO_STANDARD[pos]) == 1);

        new_board += PIECE_MATCHER[piece];
        new_board += ' ';

    }

    os << new_board << std::endl << std::endl;
    os << "side: " << p.side << " ep: " << p.ep_square << " castle: " << p.castle_ability_bits
              << " hash: " << p.hash_key << std::endl << std::endl;

    for (int piece = WHITE_PAWN; piece < EMPTY; piece++) {
        os << "Piece: " << piece << " bitboard: \n";
        print_bitboard(p.pieces[piece]);
    }
	return os;
}