#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int council_roomPlay(struct gameState *state, int currentPlayer, int handPos)
{
	int i;
	//+4 Cards
	for (i = 0; i < 4; i++)
	{
			drawCard(currentPlayer, state);
	}
	
	//+1 Buy
	state->numBuys++;
	
	//Each other player draws a card
	for (i = 0; i < state->numPlayers; i++)
	{
		/*if ( i != currentPlayer )
		{*/
  			drawCard(i, state);
		//}
	}
	
	//put played card in played card pile
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}