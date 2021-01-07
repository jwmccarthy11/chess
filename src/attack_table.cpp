// attack_table.cpp

#include "attack_table.h"

using namespace bitboard_utils;

AttackTable::AttackTable() {
    initPawnAttacks();
}

AttackTable::~AttackTable() {}

Bitboard AttackTable::maskPawnAttacks(Square square, Color color) {
    Bitboard piece   = 0ULL;
    Bitboard attacks = 0ULL;

    piece = setBit(piece, square);

    if (color) {
        // black pawn attacks
        attacks |= (piece >> P_ATK_LEFT_OFFSET  & ~mask::file_mask[A])   // southeast
                |  (piece >> P_ATK_RIGHT_OFFSET & ~mask::file_mask[H]);  // southwest
    } else {
        // white pawn attacks
        attacks |= (piece << P_ATK_LEFT_OFFSET  & ~mask::file_mask[H])   // northwest
                |  (piece << P_ATK_RIGHT_OFFSET & ~mask::file_mask[A]);  // northeast
    }

    return attacks;
}

void AttackTable::initPawnAttacks() {
    for (unsigned square = A1; square != EndSquare; square++) {
        pawn_attacks[square][White] = maskPawnAttacks( (Square) square, White );
        pawn_attacks[square][Black] = maskPawnAttacks( (Square) square, Black );
    }
}