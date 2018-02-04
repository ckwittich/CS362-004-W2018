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
	int prevHC, i, f;
	int pass = 0;
	int fail = 0;
	FILE *fp;
	char fileOut[] = "unittestresults.out";

	initializeGame(players, array, r, game);

	i = 0;
	while(i < 4)
	{
		game->whoseTurn = c;
		game->hand[c][game->handCount[c] - 1] = adventurer;

		prevHC = game->handCount[c];

		f = playCard(game->handCount[c] - 1, -1, -1, -1, game);

		if(game->hand[c][game->handCount[c] - 1] == copper || game->hand[c][game->handCount[c] - 1] == silver || game->hand[c][game->handCount[c] - 1] == gold)
		{
			if(game->hand[c][game->handCount[c] - 2] == copper || game->hand[c][game->handCount[c] - 2] == silver || game->hand[c][game->handCount[c] - 2] == gold)
				pass++;
			else
			{
				printf("TEST %d FAILED! One of the lst 2 cars in the hand was not copper/silver/gold.\n", i);
				fail++;
			}
		}
		else
		{
			printf("TEST %d FAILED! One of the lst 2 cars in the hand was not copper/silver/gold.\n", i);
			fail++;
		}

		if(game->handCount[c] == prevHC + 2)
			pass++;
		else
		{
			printf("TEST %d FAILED! handCount ! +2.\n", i);
			fail++;
		}

		if(game->numActions == 0)
			pass++;
		else
		{
			printf("TEST %d FAILED! numActions != 0.\n", i);
			fail++;
		}

		i++;
	}
	
	fp = fopen(fileOut, "a");

	printf("CARD TEST 1 RESULTS:\nTests Passed = %d\nTests Failed = %d\n\n", pass, fail);
	fprintf(fp, "CARD TEST 1 RESULTS:\nTests Passed = %d\nTests Failed = %d\n\n", pass, fail);

	fclose(fp);

	return 0;
}