// board.cpp

#include "board.h"

inline Bitboard Board::getPieceBitboard(Piece piece, Color color) {
    return piece_bb[piece] & color_bb[color];
}

inline Bitboard Board::getColorBitboard(Color color) {
    return piece_bb[Any] & color_bb[color];
}