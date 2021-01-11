// bitboard_utils.cpp

#include <iostream>
#include <bitset>
#include "bitboard.h"

void bitboard::printBitboard(Bitboard bitboard) {
    std::bitset<64> bits(bitboard);

    std::cout << '\n';

    for (int i = 7; i >= 0; i--) {
        std::cout << i+1 << "  ";
        for (int j = 0; j < 8; j++) {
            std::cout << (bits[i*8 + j] ? "@ " : ". ");
        }
        std::cout << '\n';
    }

    std::cout << "   A B C D E F G H\n\n";
    std::cout << "Dec. value: " << bitboard << '\n';
}