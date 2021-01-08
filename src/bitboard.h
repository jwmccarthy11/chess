// bitboard_utils.h

#ifndef BITBOARD_H
#define BITBOARD_H

#include <iostream>
#include "types.h"

namespace bitboard {

    constexpr Bitboard fileA = 0x0101010101010101;
    constexpr Bitboard fileB = fileA << 1;
    constexpr Bitboard fileC = fileB << 1;
    constexpr Bitboard fileD = fileC << 1;
    constexpr Bitboard fileE = fileD << 1;
    constexpr Bitboard fileF = fileE << 1;
    constexpr Bitboard fileG = fileF << 1;
    constexpr Bitboard fileH = fileG << 1;

    constexpr Bitboard rank1 = 0x00000000000000FF;
    constexpr Bitboard rank2 = rank1 << 8;
    constexpr Bitboard rank3 = rank2 << 8;
    constexpr Bitboard rank4 = rank3 << 8;
    constexpr Bitboard rank5 = rank4 << 8;
    constexpr Bitboard rank6 = rank5 << 8;
    constexpr Bitboard rank7 = rank6 << 8;
    constexpr Bitboard rank8 = rank7 << 8;

    constexpr Bitboard fileAB = fileA | fileB;
    constexpr Bitboard fileBC = fileB | fileC;
    constexpr Bitboard fileCD = fileC | fileD;
    constexpr Bitboard fileDE = fileD | fileE;
    constexpr Bitboard fileEF = fileE | fileF;
    constexpr Bitboard fileFG = fileF | fileG;
    constexpr Bitboard fileGH = fileG | fileH;

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

#endif  // BITBOARD_H
