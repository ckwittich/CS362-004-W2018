all: removeoldfiles runtests

runtests: adventurertestrun card1testrun card2testrun

removeoldfiles: *.out
	rm *.out

adventurertestcompile: dominion.c randomtestadventurer.c rngs.c interface.c
	gcc -o adventurerrandomtest dominion.c randomtestadventurer.c rngs.c interface.c -lm -coverage
	gcc -o adventurerunittest cardtest1.c dominion.c rngs.c interface.c -lm -coverage

card1testcompile: dominion.c randomtestcard1.c rngs.c interface.c
	gcc -o card1randomtestrun dominion.c randomtestcard1.c rngs.c interface.c -lm -coverage
	gcc -o card2unittest cardtest2.c dominion.c rngs.c interface.c -lm -coverage

card2testcompile: dominion.c randomtestcard2.c rngs.c interface.c
	gcc -o card2randomtestrun dominion.c randomtestcard2.c rngs.c interface.c -lm -coverage
	gcc -o card3unittest cardtest3.c dominion.c rngs.c interface.c -lm -coverage

adventurertestrun: adventurertestcompile
	adventurerrandomtest
	chmod +w randomtestadventurer.out
	gcov dominion.c -b>> randomtestadventurer.out
	rm dominion.gcda
	adventurerunittest
	gcov dominion.c -b>> unittestresults.out

card1testrun: card1testcompile
	card1randomtestrun
	chmod +w randomtestcard1.out
	gcov dominion.c -b>> randomtestcard1.out
	rm dominion.gcda
	card2unittest
	gcov dominion.c -b>> unittestresults.out

card2testrun: card2testcompile
	card2randomtestrun
	chmod +w randomtestcard2.out
	gcov dominion.c -b>> randomtestcard2.out
	rm dominion.gcda
	card3unittest
	gcov dominion.c -b>> unittestresults.out
