// attack.cpp

#include "attack.h"

Bitboard attack::pawn_masks[NumColor][NumSquare];
Bitboard attack::knight_masks[NumSquare];
Bitboard attack::king_masks[NumSquare];

void attack::init() {
    for (Square square = A1; square < NumSquare; ++square) {
        pawn_masks[White][square] = genPawnMasks(square, White);
        pawn_masks[Black][square] = genPawnMasks(square, Black);

        for (int shift : knight_shift) {
            knight_masks[square] |= attackShift(square, shift);
        }

        for (int shift : king_shift) {
            king_masks[square] |= attackShift(square, shift);
        }
    }
}

// generate pawn attacks for a given square, color
Bitboard attack::genPawnMasks(Square square, Color color) {
    return color ? attackShift(square, SE) | attackShift(square, SW)
                 : attackShift(square, NE) | attackShift(square, NW);
}

// generate bishop pseudo-attacks for a given square
Bitboard attack::genBishopMasks(Square square) {
    int rank = getRank(square);
    int file = getFile(square);
    int shift_ne = 8 * (rank - file);        // squares on NE diag have rank = file
    int shift_nw = 8 * (rank + file - 7);    // squares on NW diag have rank + file = 7

    return (signedShift(diagNE, shift_ne)
           | signedShift(diagNW, shift_nw))  // combine shifted diagonals
           & ~squareToBB(square)             // remove occupied square
           & ~edge;                          // remove edge bits
}

// generate rook pseudo-attacks for a given square
Bitboard attack::genRookMasks(Square square) {
    int rank = getRank(square);
    int file = getFile(square);
    int shift_n = 8 * rank;
    int shift_e = file;

    return (rank1 << shift_n
           | fileA << shift_e)
           & ~squareToBB(square)
           & ~edge;
}