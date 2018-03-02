#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int adventurerPlay(struct gameState *state, int currentPlayer);


int main(int argc, char const *argv[])
{
	srand(time(NULL));

	struct gameState *game;
	int numT, numTHA, numTHB, numO;
	int numG, numS, numC;
	int i, j, k, l, r;
	int cardTypes[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, great_hall, outpost};
	int treasureTypes[3] = {gold, silver, copper};
	int pass = 0;
	int fail = 0;
	int tempHand[MAX_HAND];
	int totalDeck;
	int result;
	FILE *fp;
	char fileOut[] = "randomtestadventurer.out";

	fp = fopen(fileOut, "a");

	i = 0;
	while(i < 100000)
	{
		result  = 0;
		r = rand();
		game = newGame();
		initializeGame(2, cardTypes, r, game);

		numT = rand() % 15;
		numO = rand() % 20;

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
		fprintf(fp, "#Treasures in Deck/Discard   = %d\n", numT);
		fprintf(fp, "#Other Cards in Deck/Discard = %d\n", numO);

		numG = 0;
		numS = 0;
		numC = 0;
		j = 0;
		while(j < (numT + numO))
		{
			if(game->deck[0][j] == gold)
				numG++;
			else if(game->deck[0][j] == silver)
				numS++;
			else if(game->deck[0][j] == copper)
				numC++;
			j++;
		}

		fprintf(fp, "#Gold = %d, #Silver = %d, #Copper = %d\n", numG, numS, numC);

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

		//print to testfile how many cards in the deck and in the discard
		fprintf(fp, "deckCount = %d\n", game->deckCount[0]);
		fprintf(fp, "discardCount = %d\n", game->discardCount[0]);
		
		game->handCount[0] = 0;

		//draw hand
		j = 0;
		while(j < 5)
		{
			drawCard(0, game);
			j++;
		}

		game->hand[0][0] = adventurer;

		//check number of treasures in hand before adventurerEffect is called
		numTHB = 0;
		j = 0;
		while(j < game->handCount[0])
		{
			k = game->hand[0][j];
			if(k == gold || k == silver || k == copper)
				numTHB++;
			j++;
		}

		fprintf(fp, "#Treasure in Hand Before = %d\n", numTHB);

		//check number of cards in draw and dicard before adveturerEffect is called
		totalDeck = game->deckCount[0] + game->discardCount[0];
		
		playCard(0, -1, -1, -1, game);

		//check number of treasures in hand after adventurerEffect is called
		numTHA = 0;
		j = 0;
		while(j < game->handCount[0])
		{
			k = game->hand[0][j];
			if(k == gold || k == silver || k == copper)
				numTHA++;
			j++;
		}

		fprintf(fp, "#Treasure in Hand After = %d\n", numTHA);

		//check number of cards in draw and after before adveturerEffect is called
		if(totalDeck != game->deckCount[0] + game->discardCount[0])
		{
			result = 1;
			fprintf(fp, "Deck/discard count is off by %d.\n", totalDeck - game->deckCount[0] - game->discardCount[0]);
		}

		if(numTHA != numTHB + 2)
		{
			if(numT < 2 && numTHA != numTHB + numT)
				result = 1;
		}
		
		if(result == 0)
		{
			fprintf(fp, "Test %d PASSED.\n", i + 1);
			pass++;
		}
		else
		{
			fprintf(fp, "Test %d FAILED.\n", i);
			fail++;
		}

		fprintf(fp, "\n\n");

		free(game);

		i++;
	}

	fprintf(fp, "RESULTS:\nTests Passed = %d\nTests Fails = %d\n", pass, fail);

	fclose(fp);
	
	return 0;
}