// attack.cpp

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

    for (int shift : (color ? b_pawn_shift : w_pawn_shift)) {
        attacks |= attackShift(square, shift);
    }

    return attacks;
}