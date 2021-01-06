
#include "board.h"
#include "bitboard_utils.h"

using namespace bitboard_utils;

int main() {
    Board board;
    Bitboard white_pawns;

    white_pawns = board.getWhitePawns();
    white_pawns = set_bit(white_pawns, a8);
    white_pawns = pop_bit(white_pawns, a3);
    print_bitboard(white_pawns);

    return 0;
}
