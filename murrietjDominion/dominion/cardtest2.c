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
	int players = 2;
	int r = rand();
	int c = 0;
	int f, prevHC;
	int pass = 0;
	int fail = 0;
	FILE *fp;
	char fileOut[] = "unittestresults.out";

	initializeGame(players, array, r, game);

	game->whoseTurn = c;
	game->hand[c][game->handCount[c] - 1] = smithy;

	prevHC = game->handCount[c];

	f = playCard(game->handCount[c] - 1, -1, -1, -1, game);

	if(game->handCount[c] == prevHC + 2)
		pass++;
	else
	{
		printf("TEST FAILED! handCount ! +2\n");
		fail++;
	}


	fp = fopen(fileOut, "a");

	printf("CARD TEST 2 RESULTS:\nPassed Tests =  %d\nFailed Tests = %d\n\n", pass, fail);
	fprintf(fp, "CARD TEST 2 RESULTS:\nPassed Tests =  %d\nFailed Tests = %d\n\n", pass, fail);
	
	fclose(fp);

	return 0;
}