// bitboard_utils.h

#ifndef BITBOARD_UTILS_H
#define BITBOARD_UTILS_H

#include <iostream>
#include "types.h"

namespace bitboard_utils {

    constexpr Bitboard get_bit(Bitboard bitboard, Square square) {
        return bitboard & 1ULL << square;
    }

    constexpr Bitboard set_bit(Bitboard bitboard, Square square) {
        return bitboard | 1ULL << square;
    }

    constexpr Bitboard pop_bit(Bitboard bitboard, Square square) {
        return get_bit(bitboard, square) ? bitboard ^ 1ULL << square : bitboard;
    }

    void print_bitboard(Bitboard);

}

#endif //CHESS_ENGINE_BITBOARD_UTILS_H
