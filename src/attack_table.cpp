// attack_table.cpp

#include "attack_table.h"

using namespace bitboard_utils;

AttackTable::AttackTable() {
    initLeaperAttacks();
}

Bitboard AttackTable::maskPawnAttacks(Square square, Color color) {
    Bitboard piece   = 0ULL;
    Bitboard attacks = 0ULL;

    piece = setBit(piece, square);

    if (color) {
        // black pawn attacks
        attacks |= (piece >> P_ATK_LEFT_OFFSET  & ~mask::file[A])   // southeast
                |  (piece >> P_ATK_RIGHT_OFFSET & ~mask::file[H]);  // southwest
    } else {
        // white pawn attacks
        attacks |= (piece << P_ATK_LEFT_OFFSET  & ~mask::file[H])   // northwest
                |  (piece << P_ATK_RIGHT_OFFSET & ~mask::file[A]);  // northeast
    }

    return attacks;
}

Bitboard AttackTable::maskKnightAttacks(Square square) {
    Bitboard piece   = 0ULL;
    Bitboard attacks = 0ULL;

    piece = setBit(piece, square);

    attacks |= (piece << N_ATK_WNW_OFFSET & ~mask::pair[G])
            |  (piece << N_ATK_NNW_OFFSET & ~mask::file[H])
            |  (piece << N_ATK_NNE_OFFSET & ~mask::file[A])
            |  (piece << N_ATK_ENE_OFFSET & ~mask::pair[A])
            |  (piece >> N_ATK_WNW_OFFSET & ~mask::pair[A])
            |  (piece >> N_ATK_NNW_OFFSET & ~mask::file[A])
            |  (piece >> N_ATK_NNE_OFFSET & ~mask::file[H])
            |  (piece >> N_ATK_ENE_OFFSET & ~mask::pair[G]);

    return attacks;
}

Bitboard AttackTable::maskKingAttacks(Square square) {
    Bitboard piece   = 0ULL;
    Bitboard attacks = 0ULL;

    piece = setBit(piece, square);

    attacks |= (piece << K_ATK_W_OFFSET  & ~mask::file[A])
            |  (piece << K_ATK_NW_OFFSET & ~mask::file[A])
            |  (piece << K_ATK_N_OFFSET)
            |  (piece << K_ATK_NE_OFFSET & ~mask::file[H])
            |  (piece >> K_ATK_W_OFFSET  & ~mask::file[H])
            |  (piece >> K_ATK_NW_OFFSET & ~mask::file[H])
            |  (piece >> K_ATK_N_OFFSET)
            |  (piece >> K_ATK_NE_OFFSET & ~mask::file[A]);

    return attacks;
}

void AttackTable::initLeaperAttacks() {
    for (unsigned square = A1; square != EndSquare; square++) {
        pawn_attacks[square][White] = maskPawnAttacks( (Square) square, White );
        pawn_attacks[square][Black] = maskPawnAttacks( (Square) square, Black );
        knight_attacks[square]      = maskKnightAttacks( (Square) square );
        king_attacks[square]        = maskKingAttacks( (Square) square );
    }
}