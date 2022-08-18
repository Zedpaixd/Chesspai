#include <stdio.h>
#include "definitions.h"

int main(int argc, char const *argv[])
{
    init_all();

    UNS64 playBoard = 0ULL;
    printf("Start:");
    nl(2);
    printBoard(playBoard);

    playBoard |= (1ULL << BASE_M_TO_64[D2]);
    printf("D2 added.");
    nl(2);
    printBoard(playBoard);

    return 0;
}
