#include <stdio.h>
#include "definitions.h"

void printBoard(UNS64 board){

    UNS64 temp = 1ULL;

    int rank = 0,
        file = 0,
        square = 0,
        square64 = 0;

    nl(2);
    for (rank = RANK_8; rank >= RANK_1; rank--)
    {
        for (file = FILE_A; file <= FILE_H; file++)
        {
            square = FR_TO_SQUARE(file,rank);
            square64 = BASE_M_TO_64[square];
            if ((temp << square64) & board)
                printf("X");
            else
                printf("-");
        }
        nl(1);
    }
    nl(2);
    

}