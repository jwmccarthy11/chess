// attack.h

#ifndef ATTACK_H
#define ATTACK_H

#include <array>
#include "types.h"
#include "bitboard.h"

using namespace bitboard;

namespace attack {

    constexpr int knight_shift[] = { NNE, NNW, ENE, WNW, SSE, SSW, ESE, WSW };
    constexpr int king_shift[]   = { N, S, E, W, NE, NW, SE, SW };

    // check for erroneous attack file
    constexpr bool validFile(Square from, Square to) {
        return abs(to % 8 - from % 8) <= 2;
    }

    // set bit at valid attack location
    constexpr Bitboard attackShift(Square square, int shift) {
        auto target = (Square) (square + shift);
        return validSquare(target) && validFile(square, target) ? squareToBB(target) : 0ULL;
    }

    extern Bitboard pawn_masks[NumColor][NumSquare];
    extern Bitboard knight_masks[NumSquare];
    extern Bitboard king_masks[NumSquare];

    Bitboard genPawnMasks(Square square, Color color);
    Bitboard genBishopMasks(Square square);
    Bitboard genRookMasks(Square square);

    void init();

}

#endif  // ATTACK_H
