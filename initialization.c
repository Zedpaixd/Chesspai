// init.c

#include <stdlib.h>
#include "definitions.h"

#define RANDOM64 ( (UNS64)rand() + (UNS64)rand() << 15 + (UNS64)rand() << 30 + (UNS64)rand() << 45 + ((UNS64)rand() & 0xf) << 60 )

int BASE_M_TO_64[BOARD_SQRS];
int BASE_64_TO_M[64];
UNS64 setMask[64];
UNS64 clearMask[64];

UNS64 PieceKeys[13][120];
UNS64 SideKey;
UNS64 CastleKeys[16];

void init_Hashes(){

	for(int i = 0; i<13; i++)
		for (int j = 0; j < 120; j++)
			PieceKeys[i][j] = RANDOM64;

	for(int i = 0; i<16; i++)
		CastleKeys[i] = RANDOM64;

	SideKey = RANDOM64;
}

void init_BIT_MASKS(){
	for(int index = 0; index < 64; index++){
		setMask[index] = 0ULL;
		setMask[index] |= (1ULL << index);
		clearMask[index] = ~setMask[index];
	}
}

void init_BASE_M_TO_64() {

int file = FILE_A,
    rank = RANK_1,
    square = A1,
    square64 = 0;

	for (int i = 0; i < BOARD_SQRS; i++)
    {
        BASE_M_TO_64[i] = 65;
        if (i < 64)
            BASE_64_TO_M[i] = 120;
    }
	
	for(rank = RANK_1; rank <= RANK_8; rank++) {
		for(file = FILE_A; file <= FILE_H; file++) {
			square = FR_TO_SQUARE(file,rank);
			BASE_64_TO_M[square64] = square;
			BASE_M_TO_64[square] = square64;
			square64++;
		}
	}
}

void init_all() {
	init_BASE_M_TO_64();	
	init_BIT_MASKS();
	init_Hashes();
}
