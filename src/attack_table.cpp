// attack_table.cpp

#include "attack_table.h"

using namespace bitboard_utils;
using namespace attack_table;

AttackTable::AttackTable() {}

AttackTable::~AttackTable() {}

Bitboard AttackTable::maskPawnAttacks(Square square, Color color) {
    Bitboard piece   = 0ULL;
    Bitboard attacks = 0ULL;

    piece = setBit(piece, square);

    if (color) {
        // black pawn attacks
        attacks |= (piece >> P_ATK_LEFT_OFFSET  & ~file_mask[A])  // southeast
                |  (piece >> P_ATK_RIGHT_OFFSET & ~file_mask[H]); // southwest
    } else {
        // white pawn attacks
        attacks |= (piece << P_ATK_LEFT_OFFSET  & ~file_mask[H])  // northwest
                |  (piece << P_ATK_RIGHT_OFFSET & ~file_mask[A]); // northeast
    }

    return attacks;
}

void AttackTable::initPawnAttacks() {
    for (unsigned sq = A1; sq != EndSquare; sq++) {
        pawn_attacks[sq][White] = maskPawnAttacks( (Square) sq, White );
        pawn_attacks[sq][Black] = maskPawnAttacks( (Square) sq, Black );
    }
}