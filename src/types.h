// types.h

#ifndef TYPES_H
#define TYPES_H

#include <cstdint>

typedef uint64_t Bitboard;

enum Piece {
    Pawn, Knight, Bishop, Rook, Queen, King, Any, NumPiece
};

enum Color {
    White, Black, NumColor
};

enum Square {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8,
    NumSquare
};

// Square pre-increment
inline Square& operator++(Square& s) {
    return s = Square( int(s) + 1 );
}

enum Direction {
    // cardinal directions
    N = 8,
    S = -8,
    E = 1,
    W = -1,

    // composite directions
    NE = N+E, NW = N+W,
    SE = S+E, SW = S+W,

    // tri-composite directions
    NNE = N+N+E, NNW = N+N+W,
    SSE = S+S+E, SSW = S+S+W,
    ENE = E+N+E, WNW = W+N+W,
    ESE = E+S+E, WSW = W+S+W
};

#endif  //TYPES_H
