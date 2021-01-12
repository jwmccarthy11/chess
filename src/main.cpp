// main.cpp

#include <iostream>
#include "board.h"
#include "bitboard.h"
#include "attack.h"

using namespace bitboard;

int main() {
    attack::init();

    for (Square s = A1; s < NumSquare; ++s) {
        printBitboard(attack::genRookMasks(s));
    }

    return 0;
}
