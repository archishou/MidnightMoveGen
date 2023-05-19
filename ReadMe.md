# MidnightMoveGen 

### Performance

Midnight MoveGen is a fully legal C++ move generator. Taking advantage of it requires only including the single header file located in release/move_gen.h

From there, everything is available in the MidnightMoveGen namespace.

Speed tested on a Mac M1 Pro. 
No hash-table or threading used.

Tested on 143 unique positions each at different depths. See tests/perft_results.txt for a full list of the tested positions.
```
Total Nodes: 4782919546
Elapsed Time(ms): 11381
NPS: 420254770
```

### Features
Generating a move list.
```c++
// Supports only capture generation or all moves.
Position board{START_FEN};
MoveList<WHITE, CAPTURES> capture_list(board);
MoveList<WHITE, ALL> move_list(board);
```
Building a move.
```
// Supported types: QUIET, OO, OOO, DOUBLE_PUSH, 
// CAPTURE_TYPE, ENPASSANT, PR_KNIGHT, PR_BISHOP, 
// PR_ROOK, PR_QUEEN
Move move = Move(e2, e4, QUIET);

// Promote and capture 
Move move = Move(e2, e4, CAPTURE_TYPE | PR_KNIGHT);
```
Getting attacks for a piece type at a square.
```c++
Position board{START_FEN};
// Attacks for pawn.
Bitboard white_pawn_attacks = tables::attacks<PAWN, WHITE>(a1);
Bitboard black_pawn_attacks = tables::attacks<PAWN, BLACK>(a1);

// Attacks for a knight.
Bitboard knight_attacks = tables::attacks<KNIGHT>(a1);

// Attacks for a bishop.
Bitboard bishop_attacks = tables::attacks<BISHOP>(a1, board.occupancy());

// Attacks for a rook.
Bitboard rook_attacks = tables::attacks<ROOK>(a1, board.occupancy());

// Attacks for a king.
Bitboard king_attacks = tables::attacks<KING>(a1);
```

### Example Usage

Fetch all legal moves from a position.
```c++
Position board{START_FEN};
MoveList<WHITE, ALL> move_list(board);

for (auto move : move_list) {
	std::cout << move << std::endl;
}
```

