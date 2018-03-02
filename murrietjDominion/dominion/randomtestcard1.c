#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int smithyPlay(struct gameState *state, int currentPlayer, int handPos);


int main(int argc, char const *argv[])
{
	srand(time(NULL));

	struct gameState *game;
	int numHB, numHA, numT, numO, deck, discard;
	int i, j, k, l, r;
	int cardTypes[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, great_hall, outpost};
	int treasureTypes[3] = {gold, silver, copper};
	int pass = 0;
	int fail = 0;
	FILE *fp;
	char fileOut[] = "randomtestcard1.out";

	fp = fopen(fileOut, "a");

	i = 0;
	while(i < 100000)
	{
		r = rand();
		game = newGame();
		initializeGame(2, cardTypes, r, game);

		numT = rand() % 15;
		//printf("numT = %d\n", numT);
		numO = rand() % 20;
		//printf("numO = %d\n", numO);

		game->deckCount[0] = numT + numO;

		j = 0;
		while(j < numT)
		{
			k = rand() % 3;
			game->deck[0][j] = treasureTypes[k];
			j++;
		}
		
		l = 0;
		while(l < numO)
		{
			k = rand() % 10;
			game->deck[0][j + l] = cardTypes[k];
			l++;
		}
		
		fprintf(fp, "Test %d\n", i + 1);

		r = shuffle(0, game);

		r = rand() % (numT + numO + 1);
		
		//discard a random number of cards between 0-deckCount
		k = numO + numT - 1;
		j = 0;
		while(j < r)
		{
			game->discard[0][j] = game->deck[0][k - j];
			game->deckCount[0]--;
			game->discardCount[0]++;
			j++;
		}


		deck = game->deckCount[0];
		discard = game->discardCount[0];

		game->handCount[0] = 0;

		//draw hand
		j = 0;
		while(j < 5)
		{
			drawCard(0, game);
			j++;
		}

		game->hand[0][0] = smithy;

		numHB = game->handCount[0];

		j = smithyEffect(game, 0, 0);

		numHA = game->handCount[0];

		if(numHA == numHB + 2)
		{
			pass++;
		}
		else
		{
			fprintf(fp, "deckCount = %d\n", deck);
			fprintf(fp, "discardCount = %d\n", discard);
			fprintf(fp, "Test Failed.\n");
			fail++;
		}
		i++;
	}

	fprintf(fp, "TEST RESULTS:\nPassed = %d\nFailed = %d\n", pass, fail);

	return 0;
}
