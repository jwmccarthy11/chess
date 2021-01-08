// attack.h

#ifndef ATTACK_H
#define ATTACK_H

#include <array>
#include "types.h"
#include "bitboard.h"

namespace attack {

    constexpr int w_pawn_shift[] = {7, 9};
    constexpr int b_pawn_shift[] = {-9, -7};
    constexpr int knight_shift[] = {-17, -15, -10, -6, 6, 10, 15, 17};
    constexpr int king_shift[]   = {-9, -8, -7, -1, 1, 7, 8, 9};

    extern Bitboard pawn_attacks[NumColor][NumSquare];
    extern Bitboard knight_attacks[NumSquare];
    extern Bitboard king_attacks[NumSquare];

    Bitboard maskPawnAttacks(Square square, Color color);
    Bitboard maskBishopAttacks(Square square);

    void init();
    
}

#endif  // ATTACK_H
