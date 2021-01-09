// main.cpp

#include <iostream>
#include "board.h"
#include "bitboard.h"
#include "attack.h"

using namespace bitboard;

int main() {
    attack::init();

    printBitboard(attack::knight_attacks[E4]);

    return 0;
}
