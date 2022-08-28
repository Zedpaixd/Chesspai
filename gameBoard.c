#include <stdio.h>
#include "definitions.h"

void reset_Board(BOARD_STRUCT *board)
{
    for (int i = 0; i < BOARD_SQRS; i++)
    {
        board->pieces[i] = OFFBOARD;
        if (i < 64)
            board->pieces[BASE_64_TO_M[i]] = EMPTY;
        if (i < 13)
            board->pieceNum[i] = i;
        if (i < 3)
        {
            board->pawns[i] = 0ULL;
            board->BishKn[i] = 0;
            board->King[i] = 0;
            board->RookQueen[i] = 0;
        }
    }

    board->KNGSQ[WHITE] = board->KNGSQ[BLACK] = NO_SQ;
    board->side = BOTH;
    board->enPassant = NO_SQ;
    board->moveCtr = 0;

    board->ply = 0;
    board->histPly = 0;
    board->canCastle = 0;
    board->posKey = 0ULL;
}