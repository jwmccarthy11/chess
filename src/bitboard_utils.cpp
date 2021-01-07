// bitboard_utils.cpp

#include <iostream>
#include <bitset>
#include "bitboard_utils.h"

void bitboard_utils::printBitboard(Bitboard bitboard) {
    std::bitset<64> bits(bitboard);

    // print board in console with file/rank labels
    for (int i = 7; i >= 0; i--) {
        std::cout << i+1 << "  ";
        for (int j = 0; j < 8; j++) {
            std::cout << (bits[i*8 + j] ? "@ " : ". ");
        }
        std::cout << '\n';
    }
    std::cout << "   A B C D E F G H\n\n";

    // display bitboard decimal value
    std::cout << "Dec. value: " << bitboard << '\n';
}