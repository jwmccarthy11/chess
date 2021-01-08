// attack.cpp

#include "attack.h"

Bitboard attack::pawn_attacks[NumColor][NumSquare];
Bitboard attack::knight_attacks[NumSquare];
Bitboard attack::king_attacks[NumSquare];

void attack::init() {
    for (Square square = A1; square < NumSquare; square++) {
        pawn_attacks[White][square] = maskPawnAttacks(square, White);
        pawn_attacks[Black][square] = maskPawnAttacks(square, Black);
        knight_attacks[square] = maskKnightAttacks(square);
        king_attacks[square] = maskKingAttacks(square);
    }
}

Bitboard attack::maskPawnAttacks(Square square, Color color) {
    Bitboard attacks = 0ULL;
    Bitboard square_bb = setBit(0ULL, square);

    if (color) {
        attacks |= (square_bb >> 7 & ~fileA)
                |  (square_bb >> 9 & ~fileH);
    } else {
        attacks |= (square_bb << 7 & ~fileH)
                |  (square_bb << 9 & ~fileA);
    }

    return attacks;
}

Bitboard attack::maskKnightAttacks(Square square) {
    Bitboard attacks = 0ULL;
    Bitboard square_bb = setBit(0ULL, square);

    attacks |= (square_bb << 10 & ~fileAB) | (square_bb << 17 & ~fileA)
            |  (square_bb << 15 & ~fileH)  | (square_bb << 6  & ~fileGH)
            |  (square_bb >> 10 & ~fileGH) | (square_bb >> 17 & ~fileH)
            |  (square_bb >> 15 & ~fileA)  | (square_bb >> 6  & ~fileAB);

    return attacks;
}

Bitboard attack::maskKingAttacks(Square square) {
    Bitboard attacks = 0ULL;
    Bitboard square_bb = setBit(0ULL, square);

    attacks |= (square_bb << 1 & ~fileA) | (square_bb >> 1 & ~fileH)
            |  (square_bb << 7 & ~fileH) | (square_bb >> 7 & ~fileA)
            |  (square_bb << 9 & ~fileA) | (square_bb >> 9 & ~fileH)
            |  square_bb << 8 | square_bb >> 8;

    return attacks;
}

