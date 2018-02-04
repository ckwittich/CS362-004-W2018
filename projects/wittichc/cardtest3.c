#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(int argc, char const *argv[])
{
	srand(time(NULL));
	struct gameState *game = newGame();
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int players = 4;
	int prevHC[players];
	int r = rand();
	int c = 0;
	int f, prevB, i;
	int pass = 0;
	int fail = 0;
	FILE *fp;
	char fileOut[] = "unittestresults.out";

	initializeGame(players, array, r, game);

	i = 0;
	while(i < players)
	{
		prevHC[i] = game->handCount[i];
		i++;
	}

	game->whoseTurn = c;
	game->hand[c][game->handCount[c] - 1] = council_room;
	prevB = game->numBuys;

	f = playCard(game->handCount[c] - 1, -1, -1, -1, game);

	i = 0;
	while(i < players)
	{
		if(i == c)
		{
			if(game->handCount[i] == prevHC[i] + 3)
				pass++;
			else
			{
				printf("TEST FAILED! Current player's handCount is incorrect.\n");
				fail++;
			}
		}
		else
		{
			if(game->handCount[i] == prevHC[i] + 1)
				pass++;
			else
			{
				printf("TEST FAILED! Player %d's handCount is off.\n", i);
				fail++;
			}
		}
		i++;
	}

	if(game->numBuys == prevB + 1)
		pass++;
	else
	{
		printf("TEST FAILD! numBuys is off.\n");
		fail++;
	}

	//print out results
	fp = fopen(fileOut, "a");

	printf("CARD TEST 2 RESULTS:\nPassed Tests =  %d\nFailed Tests = %d\n\n", pass, fail);
	fprintf(fp, "CARD TEST 2 RESULTS:\nPassed Tests =  %d\nFailed Tests = %d\n\n", pass, fail);
	
	fclose(fp);

	return 0;
}