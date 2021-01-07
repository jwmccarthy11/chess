// bitboard_utils.h

#ifndef BITBOARD_UTILS_H
#define BITBOARD_UTILS_H

#include <iostream>
#include "types.h"

namespace bitboard_utils {

    constexpr Bitboard getBit(Bitboard bitboard, Square square) {
        return bitboard & 1ULL << square;
    }

    constexpr Bitboard setBit(Bitboard bitboard, Square square) {
        return bitboard | 1ULL << square;
    }

    constexpr Bitboard popBit(Bitboard bitboard, Square square) {
        return getBit(bitboard, square) ? bitboard ^ 1ULL << square : bitboard;
    }

    void printBitboard(Bitboard);

}

#endif //CHESS_ENGINE_BITBOARD_UTILS_H
