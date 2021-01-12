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

    // long diagonal bit masks
    constexpr Bitboard diagNE = 0x8040201008040201;
    constexpr Bitboard diagNW = 0x0102040810204080;

    // board edge bit mask
    constexpr Bitboard edge = fileA | fileH | rank1 | rank8;

    // check for erroneous square
    constexpr bool validSquare(Square square) {
        return square >= A1 && square <= H8;
    }

    // get rank of given square
    constexpr int getRank(Square square) {
        return square >> 3;
    }

    // get file of given square
    constexpr int getFile(Square square) {
        return square & 7;
    }

    // get bit value of square on given bitboard
    constexpr Bitboard getBit(Bitboard bitboard, Square square) {
        return bitboard & 1ULL << square;
    }

    // set bit value of square on given bitboard
    constexpr Bitboard setBit(Bitboard bitboard, Square square) {
        return bitboard | 1ULL << square;
    }

    // remove bit at given square from given bitboard
    constexpr Bitboard popBit(Bitboard bitboard, Square square) {
        return getBit(bitboard, square) ? bitboard ^ 1ULL << square : bitboard;
    }

    // shift bitboard according to sign of shift
    constexpr Bitboard signedShift(Bitboard bitboard, int shift) {
        return shift > 0 ? bitboard << shift : bitboard >> -shift;
    }

    // get bitboard with given square = 1
    constexpr Bitboard squareToBB(Square square) {
        return setBit(0ULL, square);
    }

    void printBitboard(Bitboard);

}

#endif  // BITBOARD_H
