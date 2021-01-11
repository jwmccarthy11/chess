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

Bitboard attack::maskPawnAttacks(Square square, Color color) {
    Bitboard attacks = 0ULL;

    for ( int shift : (color ? black_pawn_shift : white_pawn_shift) ) {
        attacks |= attackShift(square, shift);
    }

    return attacks;
}

Bitboard attack::maskBishopAttacks(Square square) {
    int rank = square >> 3;
    int file = square &  7;
    int shift_ne = 8 * (rank - file);
    int shift_nw = 8 * (rank + file - 7);

    return signShift(diagNE, shift_ne)
        |  signShift(diagNW, shift_nw)
        ^  squareBit(square)
        &  ~edge;
}