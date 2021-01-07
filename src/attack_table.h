// attack_table.h

#ifndef ATTACK_TABLE_H
#define ATTACK_TABLE_H

#define P_ATK_LEFT_OFFSET  7
#define P_ATK_RIGHT_OFFSET 9

#include <array>
#include "types.h"
#include "mask.h"
#include "bitboard_utils.h"

class AttackTable {
public:
    AttackTable();
    ~AttackTable();

    static Bitboard maskPawnAttacks(Square square, Color color);

    void initPawnAttacks();

    inline Bitboard getWhitePawnAttacks(Square square) { return pawn_attacks[square][White]; }
    inline Bitboard getBlackPawnAttacks(Square square) { return pawn_attacks[square][Black]; }

private:
    std::array<std::array<Bitboard, 2>, 64> pawn_attacks;
};

#endif  // ATTACK_H
