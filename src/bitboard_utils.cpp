// bitboard_utils.cpp

#include <iostream>
#include <bitset>
#include "bitboard_utils.h"

#define BOARD_DIM 8

void bitboard_utils::print_bitboard(Bitboard bitboard) {
    std::bitset<64> bits(bitboard);

    // print board in console with file/rank labels
    for (int i = BOARD_DIM-1; i >= 0; i--) {
        std::cout << i+1 << "  ";
        for (int j = 0; j < BOARD_DIM; j++) {
            bits[i*BOARD_DIM + j] ? std::cout << "@ " : std::cout << ". ";
        }
        std::cout << '\n';
    }
    std::cout << "   A B C D E F G H\n\n";

    // display bitboard decimal value
    std::cout << "Dec. value: " << bitboard << '\n';
}