// board.h

#ifndef CHESS_ENGINE_BOARD_H
#define CHESS_ENGINE_BOARD_H

#define NUM_PIECE 6
#define NUM_COLOR 2
#define NUM_OCCUP 2

#include <array>
#include "types.h"

class Board {
public:
    Board();
    ~Board();

    // piece bitboard getters
    inline Bitboard getWhitePawns()   const { return piece_bb[Pawn]   & color_bb[White]; }
    inline Bitboard getBlackPawns()   const { return piece_bb[Pawn]   & color_bb[Black]; }
    inline Bitboard getWhiteKnights() const { return piece_bb[Knight] & color_bb[White]; }
    inline Bitboard getBlackKnights() const { return piece_bb[Knight] & color_bb[Black]; }
    inline Bitboard getWhiteBishops() const { return piece_bb[Bishop] & color_bb[White]; }
    inline Bitboard getBlackBishops() const { return piece_bb[Bishop] & color_bb[Black]; }
    inline Bitboard getWhiteRooks()   const { return piece_bb[Rook]   & color_bb[White]; }
    inline Bitboard getBlackRooks()   const { return piece_bb[Rook]   & color_bb[Black]; }
    inline Bitboard getWhiteQueens()  const { return piece_bb[Queen]  & color_bb[White]; }
    inline Bitboard getBlackQueens()  const { return piece_bb[Queen]  & color_bb[Black]; }
    inline Bitboard getWhiteKing()    const { return piece_bb[King]   & color_bb[White]; }
    inline Bitboard getBlackKing()    const { return piece_bb[King]   & color_bb[Black]; }

    // utility bitboard getters
    inline Bitboard getWhitePieces()    const { return color_bb[White]; }
    inline Bitboard getBlackPieces()    const { return color_bb[Black]; }
    inline Bitboard getOccupiedPieces() const { return occup_bb[Occupied]; }
    inline Bitboard getVacantPieces()   const { return occup_bb[Vacant]; }

private:
    std::array<Bitboard, NUM_PIECE> piece_bb;
    std::array<Bitboard, NUM_COLOR> color_bb;
    std::array<Bitboard, NUM_COLOR> occup_bb;
};

#endif //CHESS_ENGINE_BOARD_H
