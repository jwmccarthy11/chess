#include <iostream>
#include <bitset>

#include "board.h"

int main() {
    Board board;
    U64 whitePawns;
    U64 blackPawns;
    U64 allPawns;

    whitePawns = board.getWhitePawns();
    blackPawns = board.getBlackPawns();
    allPawns = whitePawns | blackPawns;

    std::bitset<64> x(allPawns);

    // print pawn locations
    for (int i = 0; i < 64; i++) {
        std::cout << x[i];
        if (i % 8 == 7) {
            std::cout << '\n';
        }
    }
}
