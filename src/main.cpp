// main.cpp

#include <iostream>
#include "board.h"
#include "bitboard.h"
#include "attack.h"

using namespace bitboard;
using namespace attack;

int main() {
    init();

    printBitboard(knight_attacks[G6]);

    return 0;
}
