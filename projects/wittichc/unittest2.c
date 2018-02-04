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
	int i, j , k;
	int array[27] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4};
	int pass = 0;
	int fail = 0;
	FILE *fp;
	char fileOut[] = "unittestresults.out";

	i = 0;
	while(i < 100)
	{
		j = rand() % 27;
		if(array[j] == getCost(j))
			pass++;
		else
			fail++;
		i++;
	}

	i = 0;
	while(i < 100)
	{
		j = i + 27;
		if(getCost(j) == -1)
			pass++;
		else
			fail++;
		i++;
	}
	fp = fopen(fileOut, "a");

	printf("UNIT TEST 2 RESULTS:\nTests passed = %d\nTests failed = %d\n", pass, fail);
	fprintf(fp, "\n\nUNIT TEST 2 RESULTS:\nTests passed = %d\nTests failed = %d\n\n", pass, fail);

	fclose(fp);

	return 0;
}