#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int council_roomPlay(struct gameState *state, int currentPlayer, int handPos);


int main(int argc, char const *argv[])
{
	srand(time(NULL));

	struct gameState *game;
	int numHB, numHA;
	int i, j, k, l, r, p;
	int handCountsBefore[4];
	int cardTypes[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, great_hall, outpost};
	int pass = 0;
	int fail = 0;
	FILE *fp;
	char fileOut[] = "randomtestcard2.out";

	fp = fopen(fileOut, "a");

	i = 0;
	while(i < 100000)
	{
		r = rand();
		p = r % 3 + 2;
		l = rand() % p;
		game = newGame();
		initializeGame(p, cardTypes, r, game);

		game->hand[l][0] = council_room;

		j = 0;
		while(j < p)
		{
			handCountsBefore[j] = game->handCount[j];
			j++;
		}

		j = council_roomPlay(game, l, 0);

		j = 0;
		k = 0;
		while(j < p)
		{
			if(j == l)
			{
				if(game->handCount[j] != handCountsBefore[j] + 3)
					k = 1;
			}
			else
			{
				if(game->handCount[j] != handCountsBefore[j] + 1)
					k = 1;
			}
			j++;
		}

		if(k == 0)
		{
			pass++;
		}
		else
		{
			fprintf(fp, "Test %d Failed.\n", i + 1);
			j = 0;
			while(j < p)
			{
				if(j == l)
				{
					if(game->handCount[j] != handCountsBefore[j] + 3)
						fprintf(fp, "Current player handsize incorrect.\nBefore = %d\nAfter = %d\n", handCountsBefore[j], game->handCount[j]);
				}
				else
				{
					if(game->handCount[j] != handCountsBefore[j] + 1)
						fprintf(fp, "Other player handsize incorrect.\nBefore = %d\nAfter = %d\n", handCountsBefore[j], game->handCount[j]);
				}
				j++;
			}
			fail++;
		}
		i++;
	}

	fprintf(fp, "TEST RESULTS:\nPassed = %d\nFailed = %d\n", pass, fail);

	return 0;
}
