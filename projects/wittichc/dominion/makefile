all: removeoldfiles runtests

runtests: adventurertestrun card1testrun card2testrun

removeoldfiles: *.out
	rm *.out

adventurertestcompile: dominion.c adventurer.c randomtestadventurer.c rngs.c interface.c smithy.c
	gcc -o adventurertest dominion.c adventurer.c randomtestadventurer.c rngs.c interface.c smithy.c council_room.c -lm -coverage

card1testcompile: dominion.c smithy.c randomtestcard1.c rngs.c interface.c adventurer.c
	gcc -o card1testrun dominion.c smithy.c randomtestcard1.c rngs.c interface.c adventurer.c council_room.c -lm -coverage

card2testcompile: dominion.c smithy.c randomtestcard2.c rngs.c interface.c adventurer.c council_room.c
	gcc -o card2testrun dominion.c smithy.c randomtestcard2.c rngs.c interface.c adventurer.c council_room.c -lm -coverage

adventurertestrun: adventurertestcompile
	adventurertest
	chmod +w randomtestadventurer.out
	touch adventurer.gcda
	gcov adventurer.c -b>> randomtestadventurer.out

card1testrun: card1testcompile
	card1testrun
	chmod +w randomtestcard1.out
	touch smithy.gcda
	gcov smithy.c -b>> randomtestcard1.out

card2testrun: card2testcompile
	card2testrun
	chmod +w randomtestcard2.out
	touch council_room.gcda
	gcov council_room.c -b>> randomtestcard2.out