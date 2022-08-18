// #include "definitions.h"

// int BASE_M_TO_64[BOARD_SQRS];
// int BASE_64_TO_M[64];

// void init_BASE_M_TO_64(){

//     int file = FILE_A,
//         rank = RANK_1,
//         square = A1,
//         square64 = 0;

//     // for (int i = 0; i < BOARD_SQRS; ++i)
//     // {
//     //     BASE_M_TO_64[i] = 65;
//     //     if (i < 64)
//     //         BASE_64_TO_M[i] = 120;
//     // }

//     for (int i = 0; i < BOARD_SQRS; ++i)
//     {
//         BASE_M_TO_64[i] = 65;
            
//     }
//     for (int i = 0; i<64; ++i)
//     {
//         BASE_64_TO_M[i] = 120;
//     }

//     for (rank = RANK_1; rank<= RANK_8; ++rank){
//         for (file = FILE_A; file <= FILE_H; ++file)
//             square = FR_TO_SQUARE(file,rank);
//             BASE_64_TO_M[square64] = square;
//             BASE_M_TO_64[square] = square64;
//             square64++;
//     }
// }

// void init_all(){

//     init_BASE_M_TO_64();
    

// }


// init.c

#include "definitions.h"

int BASE_M_TO_64[BOARD_SQRS];
int BASE_64_TO_M[64];


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
}
