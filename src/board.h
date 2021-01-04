// board.h

#ifndef CHESS_ENGINE_BOARD_H
#define CHESS_ENGINE_BOARD_H

#include <array>
#include "types.h"

class Board {
public:
    Board();
    ~Board();

    inline U64 getWhitePawns() { return piece_bb[Pawn] & color_bb[White]; }
    inline U64 getBlackPawns() { return piece_bb[Pawn] & color_bb[Black]; }

private:
    std::array<U64, 6> piece_bb;  // piece location bitboards
    std::array<U64, 2> color_bb;  // piece color bitboards
    std::array<U64, 2> occup_bb;  // square occupancy bitboards

    int turn_color;
    int castling_rights;
};

#endif //CHESS_ENGINE_BOARD_H
