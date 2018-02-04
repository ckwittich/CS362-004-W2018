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
	int before[10];
	int players = 2;
	int r = rand();
	int i, j, k, f;
	int pass = 0;
	int fail = 0;
	FILE *fp;
	char fileOut[] = "unittestresults.out";

	initializeGame(players, array, r, game);

	i = 0;
	while(i < 100)
	{
		j = 0;
		while(j < 10)
		{
			before[j] = game->deck[1][j];
			printf("%d ", before[j]);
			j++;
		}
		printf("\n");

		shuffle(1, game);

		j = 0;
		f = 0;
		while(j < 10)
		{
			if(before[j] == game->deck[1][j])
				f++;
			printf("%d ", game->deck[1][j]);
			j++;
		}
		printf("\n");

		if(f == 10)
		{
			fail++;
			printf("TEST FAILED! Cards in same order.\n");
		}
		else
		{
			pass++;
			printf("TEST SUCCESS! Cards shuffled.\n");
		}
		i++;
	}

	fp = fopen(fileOut, "w");
	
	printf("\n");
	printf("UNIT TEST 1 RESULTS:\nTests Passed = %d\n Tests Failed = %d\n", pass, fail);
	fprintf(fp, "UNIT TEST 1 RESULTS:\nTests Passed = %d\n Tests Failed = %d\n\n", pass, fail);
	
	fclose(fp);
	return 0;
}