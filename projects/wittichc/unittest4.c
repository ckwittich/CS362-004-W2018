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
	struct gameState *game = newGame();
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int i, j;
	int players = 4;
	int r = rand();
	int pass = 0;
	int fail = 0;
	FILE *fp;
	char fileOut[] = "unittestresults.out";


	players = 1;
	while(players < 5)
	{
		initializeGame(players, array, r, game);
		game->whoseTurn = 1;
		
		j = 0;
		while(j < 20)
		{
			i = 1;
			while(i < players + 1)
			{
				if(i == whoseTurn(game))
					pass++;
				else
					fail++;
				if(game->whoseTurn == players)
					game->whoseTurn = 1;
				else
					game->whoseTurn++;
				i++;
			}
			j++;
		}

		players++;
	}

	fp = fopen(fileOut, "a");

	printf("UNIT TEST 4 RESULTS:\nTests passed = %d\nTests failed = %d\n", pass, fail);
	fprintf(fp, "\n\nUNIT TEST 4 RESULTS:\nTests passed = %d\nTests failed = %d\n\n", pass, fail);

	fclose(fp);

	return 0;
}