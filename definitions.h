#ifndef DEFS_H
#define DEFS_H

#include "stdlib.h"

#define DEBUG

#ifndef DEBUG
#define ASSERT_EQUALS(n)
#else
#define ASSERT_EQUALS(n) \
    if(!(n)) { \
        printf("%s - Failed",#n); \
        printf("In File %s ",__FILE__); \
        printf("At Line %d\n",__LINE__); \
exit(1);}
#endif

typedef unsigned long long UNS64;

#define NAME "Chesspai"
#define VERSION 1.0
#define BOARD_SQRS 120

#define MAXMOVES 2048


enum { EMPTY, WP, WN, WB, WR, WQ, WK, BP, BN, BB, BR, BQ, BK};
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };

enum { WHITE, BLACK, BOTH };

enum {
  A1 = 21, B1, C1, D1, E1, F1, G1, H1,
  A2 = 31, B2, C2, D2, E2, F2, G2, H2,
  A3 = 41, B3, C3, D3, E3, F3, G3, H3,
  A4 = 51, B4, C4, D4, E4, F4, G4, H4,
  A5 = 61, B5, C5, D5, E5, F5, G5, H5,
  A6 = 71, B6, C6, D6, E6, F6, G6, H6,
  A7 = 81, B7, C7, D7, E7, F7, G7, H7,
  A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};

enum { FALSE, TRUE };

enum { WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8 };

typedef struct{

    int move,
        canCastle,
        enPassant,
        moveCtr;
    UNS64 posKey;

} UNDO_STRUCT;

typedef struct {

    int pieces[BOARD_SQRS];

    int pieceNum[13];
    UNS64 pawns[3];

    int BishKn[3],
        RookQueen[3],
        King[3];

    int KNGSQ[2];

    int canCastle;

    int side, 
        enPassant,
        moveCtr;

    int ply,
        histPly;

    UNS64 posKey;

    UNDO_STRUCT history[MAXMOVES];

    int pList[13][10];

} BOARD_STRUCT;

#define nl(i) for (int x = 0; x < i; x++) printf("\n");
#define FR_TO_SQUARE(f,r) ( (21 + (f) ) + ( (r) * 10 ) ) 

extern int BASE_M_TO_64[BOARD_SQRS];
extern int BASE_64_TO_M[64];

extern void init_all();
extern void printBoard(UNS64 board);

#endif