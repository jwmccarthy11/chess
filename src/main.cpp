
#include "board.h"
#include "bitboard_utils.h"
#include "attack_table.h"

using namespace bitboard_utils;
using namespace mask;

int main() {
    AttackTable atk_tbl;

    Bitboard a1_atk = atk_tbl.getBlackPawnAttacks(B8);

    printBitboard(a1_atk);

    return 0;
}
