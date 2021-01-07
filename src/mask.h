// mask.h

#ifndef MASK_H
#define MASK_H

namespace mask {

    const std::array<Bitboard, 8> file_mask = {
            0x0101010101010101,  // A
            0x0202020202020202,  // B
            0x0404040404040404,  // C
            0x0808080808080808,  // D
            0x1010101010101010,  // E
            0x2020202020202020,  // F
            0x4040404040404040,  // G
            0x8080808080808080   // H
    };

    const std::array<Bitboard, 8> rank_mask = {
            0x00000000000000FF,  // 1
            0x000000000000FF00,  // 2
            0x0000000000FF0000,  // 3
            0x00000000FF000000,  // 4
            0x000000FF00000000,  // 5
            0x0000FF0000000000,  // 6
            0x00FF000000000000,  // 7
            0xFF00000000000000   // 8
    };

    const std::array<Bitboard, 7> file_pair_mask = {
            0x0303030303030303,  // A & B
            0x0606060606060606,  // B & C
            0x0C0C0C0C0C0C0C0C,  // C & D
            0x1818181818181818,  // D & E
            0x3030303030303030,  // E & F
            0x6060606060606060,  // F & G
            0xC0C0C0C0C0C0C0C0   // G & H
    };

}

#endif  // MASK_H
