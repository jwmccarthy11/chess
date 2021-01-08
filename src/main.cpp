// main.cpp

#include <iostream>
#include "board.h"
#include "bitboard.h"
#include "attack.h"

using namespace bitboard;
using namespace attack;

int main() {
    init();

    printBitboard(pawn_attacks[White][E4]);

    return 0;
}
