#include "definitions.h"
#include <stdio.h>

UNS64 GeneratePositionKey(const BOARD_STRUCT *board) {

	int sq = 0;
	UNS64 finalKey = 0;
	int piece = EMPTY;
	
	// pieces
	for(sq = 0; sq < BOARD_SQRS; ++sq) {
		piece = board->pieces[sq];
		if(piece!=NO_SQ && piece!=EMPTY) {
			ASSERT_EQUALS(piece>=WP && piece<=BK);
			finalKey ^= PieceKeys[piece][sq];
		}		
	}
	
	if(board->side == WHITE) {
		finalKey ^= SideKey;
	}
		
	if(board->enPassant != NO_SQ) {
		ASSERT_EQUALS(board->enPassant>=0 && board->enPassant<BOARD_SQRS);
		finalKey ^= PieceKeys[EMPTY][board->enPassant];
	}
	
	ASSERT_EQUALS(board->canCastle>=0 && board->canCastle<=15);
	
	finalKey ^= CastleKeys[board->canCastle];
	
	return finalKey;
}


