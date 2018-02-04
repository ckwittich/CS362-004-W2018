#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	srand(time(NULL));

	struct gameState *game = newGame();
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int x[3];
	int players = 2;
	int r = rand();
	int i, j, k, f, p;
	int pass = 0;
	int fail = 0;
	FILE *fp;
	char fileOut[] = "unittestresults.out";

	f = initializeGame(players, array, r, game);

	f = isGameOver(game);

	if(f == 0)
	{
		printf("TEST SUCCESS! Requirements for gameOver not met.\n");
		pass++;
	}
	else
	{
		printf("TEST FAIL! gameOver triggered when it should not have.\n");
		fail++;
	}

	game->supplyCount[province] = 0;

	f = isGameOver(game);

	if(f == 1)
	{
		printf("TEST SUCCESS! Province count set to 0, gameOver triggered.\n");
		pass++;
	}
	else
	{
		printf("TEST FAIL! Province count set to 0, gameOver should have been triggered.\n");
		fail++;
	}

	game->supplyCount[province] = 3;

	j = 0;
	while(j < 10)
	{
		i = 0;
		while(i < 3)
		{
			x[i] = -1;
			i++;
		}

		p = 0;
		i = 0;
		while(i < 3)
		{
			do
			{
				r = rand() % 10;
			}while(r == province);
			
			k = 0;
			while(k < 3)
			{
				if(r == x[k])
					p++;
				k++;
			}
			x[i] = r;
			i++;
		}

		i = 0;
		while(i < 3)
		{
			game->supplyCount[x[i]] = 0;
			i++;
		}

		f = isGameOver(game);

		if(p == 0)
		{
			if(f == 1)
			{
				printf("TEST SUCCESS! 3 card piles empty, gmeOver correctly triggered.\n");
				pass++;
			}
			else
			{
				printf("TEST FAILED! 3 card pile empty, gameOver should have been triggered.\n");
				fail++;
			}
		}
		else
		{
			if(f == 1)
			{
				printf("TEST FAILED! < 3 card pile empty, gameOver incorrectly triggered.\n");
				fail++;
			}
			else
			{
				printf("TEST SUCCESS! < 3 card piles empty, gameOver correctly not triggered.\n");
				pass++;
			}
		}

		i = 0;
		while(i < 3)
		{
			game->supplyCount[x[i]] = 10;
			i++;
		}
		j++;
	}
	
	fp = fopen(fileOut, "a");

	printf("UNIT TEST 3 RESULTS:\nTests Passed = %d\nTests Failed = %d\n", pass, fail);
	fprintf(fp, "\n\nUNIT TEST 3 RESULTS:\nTests Passed = %d\nTests Failed = %d\n\n", pass, fail);

	fclose(fp);

	return 0;
}