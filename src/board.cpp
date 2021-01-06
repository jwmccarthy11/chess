// board.cpp

#include "board.h"

Board::Board() {
    piece_bb[Pawn]  = 0x0000002000039000;
    color_bb[White] = 0x0000002000039000;
}

Board::~Board() {

}