// attack_table.h

#ifndef ATTACK_TABLE_H
#define ATTACK_TABLE_H

// pawn attack bitshift offsets
#define P_ATK_LEFT_OFFSET  7
#define P_ATK_RIGHT_OFFSET 9

// knight attack bitshift offsets
#define N_ATK_WNW_OFFSET  6
#define N_ATK_NNW_OFFSET 15
#define N_ATK_NNE_OFFSET 17
#define N_ATK_ENE_OFFSET 10

// king attack bitshift offsets
#define K_ATK_W_OFFSET  1
#define K_ATK_NW_OFFSET 9
#define K_ATK_N_OFFSET  8
#define K_ATK_NE_OFFSET 7

#include <array>
#include "types.h"
#include "mask.h"
#include "bitboard_utils.h"

class AttackTable {
public:
    AttackTable();

    // attack bitboard generators
    static Bitboard maskPawnAttacks(Square square, Color color);
    static Bitboard maskKnightAttacks(Square square);
    static Bitboard maskKingAttacks(Square square);

    // attack bitboard initializers
    void initLeaperAttacks();

    // attack bitboard getters
    inline Bitboard getWhitePawnAttacks(Square square) { return pawn_attacks[square][White]; }
    inline Bitboard getBlackPawnAttacks(Square square) { return pawn_attacks[square][Black]; }
    inline Bitboard getKnightAttacks(Square square)    { return knight_attacks[square]; }
    inline Bitboard getKingAttacks(Square square)      { return king_attacks[square]; }

private:
    std::array<std::array<Bitboard, 2>, 64> pawn_attacks;
    std::array<Bitboard, 64> knight_attacks;
    std::array<Bitboard, 64> king_attacks;
};

#endif  // ATTACK_H
