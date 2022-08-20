#include <stdio.h>
#include "definitions.h"

const int Table[64] = {
  63, 30, 3, 32, 25, 41, 22, 33, 15, 50, 42, 13, 11, 53, 19, 34, 61, 29, 2,
  51, 21, 43, 45, 10, 18, 47, 1, 54, 9, 57, 0, 35, 62, 31, 40, 4, 49, 5, 52,
  26, 60, 6, 23, 44, 46, 27, 56, 16, 7, 39, 48, 24, 59, 14, 12, 55, 38, 28,
  58, 20, 37, 17, 36, 8
};

   // https://www.chessprogramming.org/Looking_for_Magics !!

int pop(UNS64 *bmap)
{
    UNS64 bit = *bmap ^ (*bmap - 1);
    unsigned int fold = (unsigned) ((bit & 0xffffffff) ^ (bit >> 32));
    *bmap &= (*bmap - 1);
    return Table[(fold * 0x783a9b23) >> 26]; 
}

int countBits(UNS64 bit)
{
    int ctr=0;
    for(ctr = 0; bit; ctr++, bit &= bit-1);
    return ctr;
}

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