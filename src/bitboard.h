// bitboard_utils.h

#ifndef BITBOARD_H
#define BITBOARD_H

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "types.h"

namespace bitboard {

    // file bit masks
    constexpr Bitboard fileA = 0x0101010101010101;
    constexpr Bitboard fileB = fileA << 1;
    constexpr Bitboard fileC = fileB << 1;
    constexpr Bitboard fileD = fileC << 1;
    constexpr Bitboard fileE = fileD << 1;
    constexpr Bitboard fileF = fileE << 1;
    constexpr Bitboard fileG = fileF << 1;
    constexpr Bitboard fileH = fileG << 1;

    // rank bit masks
    constexpr Bitboard rank1 = 0x00000000000000FF;
    constexpr Bitboard rank2 = rank1 << 8;
    constexpr Bitboard rank3 = rank2 << 8;
    constexpr Bitboard rank4 = rank3 << 8;
    constexpr Bitboard rank5 = rank4 << 8;
    constexpr Bitboard rank6 = rank5 << 8;
    constexpr Bitboard rank7 = rank6 << 8;
    constexpr Bitboard rank8 = rank7 << 8;

    // consecutive file pair bit masks
    constexpr Bitboard fileAB = fileA | fileB;
    constexpr Bitboard fileBC = fileB | fileC;
    constexpr Bitboard fileCD = fileC | fileD;
    constexpr Bitboard fileDE = fileD | fileE;
    constexpr Bitboard fileEF = fileE | fileF;
    constexpr Bitboard fileFG = fileF | fileG;
    constexpr Bitboard fileGH = fileG | fileH;

    // get bit value of square on given bitboard
    constexpr Bitboard getBit(Bitboard bitboard, Square square) {
        return bitboard & 1ULL << square;
    }

    // set bit value of square on given bitboard
    constexpr Bitboard setBit(Bitboard bitboard, Square square) {
        return bitboard | 1ULL << square;
    }

    // get bitboard with given square = 1
    constexpr Bitboard squareBit(Square square) {
        return 1ULL << square;
    }

    // set bit value of square to 0 on given bitboard
    constexpr Bitboard popBit(Bitboard bitboard, Square square) {
        return getBit(bitboard, square) ? bitboard ^ 1ULL << square : bitboard;
    }

    // check for erroneous attack square
    constexpr bool validSquare(Square square) {
        return square >= A1 && square <= H8;
    }

    void printBitboard(Bitboard);

}

#endif  // BITBOARD_H
