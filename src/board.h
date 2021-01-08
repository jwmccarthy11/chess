// board.h

#ifndef BOARD_H
#define BOARD_H

#include <array>
#include "types.h"

class Board {
public:
    Board() = default;

    Bitboard getPieceBitboard(Piece piece, Color color);
    Bitboard getColorBitboard(Color color);

private:
    Bitboard piece_bb[NumPiece];
    Bitboard color_bb[NumColor];
};

#endif  // BOARD_H
