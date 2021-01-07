// attack_table.h

#ifndef ATTACK_TABLE_H
#define ATTACK_TABLE_H

#define P_ATK_LEFT_OFFSET  7
#define P_ATK_RIGHT_OFFSET 9

#include <array>
#include "types.h"
#include "bitboard_utils.h"

namespace attack_table {

    const std::array<Bitboard, 8> file_mask = {
        0x0101010101010101,  // a
        0x0202020202020202,  // b
        0x0404040404040404,  // c
        0x0808080808080808,  // d
        0x1010101010101010,  // e
        0x2020202020202020,  // f
        0x4040404040404040,  // g
        0x8080808080808080   // h
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

    class AttackTable {
    public:
        AttackTable();
        ~AttackTable();

        static Bitboard maskPawnAttacks(Square square, Color color);

        void initPawnAttacks();

        inline Bitboard getWhitePawnAttacks(Square square) { return pawn_attacks[square][White]; }

    private:
        std::array<std::array<Bitboard, 2>, 64> pawn_attacks;
    };

}

#endif // ATTACK_H
