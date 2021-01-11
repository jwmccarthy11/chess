// attack.cpp

#include <iostream>
#include "attack.h"

Bitboard attack::pawn_attacks[NumColor][NumSquare];
Bitboard attack::knight_attacks[NumSquare];
Bitboard attack::king_attacks[NumSquare];

void attack::init() {
    for (Square square = A1; square < NumSquare; ++square) {
        pawn_attacks[White][square] = maskPawnAttacks(square, White);
        pawn_attacks[Black][square] = maskPawnAttacks(square, Black);

        for (int shift : knight_shift) {
            knight_attacks[square] |= attackShift(square, shift);
        }

        for (int shift : king_shift) {
            king_attacks[square] |= attackShift(square, shift);
        }
    }
}

// generate pawn attacks for a given square, color
Bitboard attack::maskPawnAttacks(Square square, Color color) {
    Bitboard attacks = 0ULL;

    for ( int shift : (color ? black_pawn_shift : white_pawn_shift) ) {
        attacks |= attackShift(square, shift);
    }

    return attacks;
}

// generate bishop pseudo-attacks for a given square
Bitboard attack::maskBishopAttacks(Square square) {
    int rank = square >> 3;
    int file = square &  7;
    int shift_ne = 8 * (rank - file);
    int shift_nw = 8 * (rank + file - 7);

    return ((signedShift(diagNE, shift_ne)
           | signedShift(diagNW, shift_nw))  // combine shifted diagonals
           ^ squareToBitboard(square))       // remove occupied square
           & ~edge;                          // remove edge bits
}