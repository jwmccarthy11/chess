// board.cpp

#include "board.h"

Board::Board() {
    // traditional chess board setup
    piece_bb[Pawn]     = 0x00FF00000000FF00;
    piece_bb[Knight]   = 0x4200000000000042;
    piece_bb[Bishop]   = 0x2400000000000024;
    piece_bb[Rook]     = 0x8100000000000081;
    piece_bb[Queen]    = 0x1000000000000010;
    piece_bb[King]     = 0x0800000000000008;
    color_bb[White]    = 0x000000000000FFFF;
    color_bb[Black]    = 0xFFFF000000000000;
    occup_bb[Occupied] = 0xFFFF00000000FFFF;
    occup_bb[Vacant]   = 0x0000FFFFFFFF0000;
}

Board::~Board() {

}