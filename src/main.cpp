
#include "board.h"
#include "bitboard_utils.h"
#include "attack_table.h"

using namespace bitboard_utils;
using namespace attack_table;

int main() {
    AttackTable atk_tbl;

    atk_tbl.initPawnAttacks();

    Bitboard a1_atk = atk_tbl.getWhitePawnAttacks(A1);

    printBitboard(a1_atk);

    return 0;
}
