// attack.h

#ifndef ATTACK_H
#define ATTACK_H

#include <array>
#include "types.h"
#include "bitboard.h"

using namespace bitboard;

namespace attack {

    extern Bitboard pawn_attacks[NumColor][NumSquare];
    extern Bitboard knight_attacks[NumSquare];
    extern Bitboard king_attacks[NumSquare];

    Bitboard maskPawnAttacks(Square square, Color color);
    Bitboard maskKnightAttacks(Square square);
    Bitboard maskKingAttacks(Square square);

    void init();
}

#endif  // ATTACK_H
