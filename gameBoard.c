#include <stdio.h>
#include "definitions.h"

int FEN_Parser(char *FEN, BOARD_STRUCT *board)
{
    ASSERT_EQUALS(FEN != NULL);
    ASSERT_EQUALS(board != NULL);

    int rank = RANK_8,
        file = FILE_A,
        piece = 0,
        counter = 0,
        MTO64 = 0,
        _64TOM = 0;

    reset_Board(board);

    while ((rank >= RANK_1) && *FEN)
    {
        counter = 1;
        switch (*FEN)
        { // DEFINITELY swap to a hash map later on
        case 'k':
            piece = BK;
            break;
        case 'q':
            piece = BQ;
            break;
        case 'b':
            piece = BB;
            break;
        case 'n':
            piece = BN;
            break;
        case 'r':
            piece = BR;
            break;
        case 'p':
            piece = BP;
            break;

        case 'K':
            piece = WK;
            break;
        case 'Q':
            piece = WQ;
            break;
        case 'B':
            piece = WB;
            break;
        case 'N':
            piece = WN;
            break;
        case 'R':
            piece = WR;
            break;
        case 'P':
            piece = WP;
            break;

        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
            piece = EMPTY;
            counter = *FEN - '0';
            break;

        case '/':
        case ' ':
            rank--;
            file = FILE_A;
            FEN++;
            continue;

        default:
            printf("gameBoard.c -- FEN_parser(...) -- line 4\n");
            return -1;
        }

        for (int i = 0; i < counter; i++)
        {
            MTO64 = rank * 8 + file;
            _64TOM = BASE_64_TO_M[MTO64];
            if (piece != EMPTY)
            {
                board->pieces[_64TOM] = piece;
            }
            file++;
        }
        FEN++;
    }

    ASSERT_EQUALS(*FEN == 'w' || *FEN == 'b');

    board->side = (*FEN == 'w') ? WHITE : BLACK;
    FEN += 2;

    for (int i = 0; i < 4; i++)
    {
        if (*FEN == ' ')
            break;
        switch (*FEN)
        {
        case 'K':
            board->canCastle |= WKCA;
            break;
        case 'Q':
            board->canCastle |= WQCA;
            break;
        case 'k':
            board->canCastle |= BKCA;
            break;
        case 'q':
            board->canCastle |= BQCA;
            break;
        default:
            break;
        }
        FEN++;
    }
    FEN++;

    ASSERT_EQUALS(board->canCastle >= 0 && board->canCastle < 16);
    if (*FEN != '-')
    {
        file = FEN[0] = 'a';
        rank = FEN[1] = '1';

        ASSERT_EQUALS(file >= FILE_A && file <= FILE_H);
        ASSERT_EQUALS(rank >= RANK_1 && rank <= RANK_8);

        board->enPassant = FR_TO_SQUARE(file, rank);
    }

    board->posKey = GeneratePositionKey(board);

    return 0;
}

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