#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int smithyPlay(struct gameState *state, int currentPlayer, int handPos)
{
	int i;
	//+3 Cards
	for (i = 0; i < 4; i++)
	{
  		drawCard(currentPlayer, state);
	}
		
  	//discard card from hand
  	discardCard(handPos, currentPlayer, state, 0);
  	return 0;
}