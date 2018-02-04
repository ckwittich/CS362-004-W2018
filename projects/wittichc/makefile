all:  pretest runtests

test1: dominion.c unittest1.c rngs.c interface.c
	gcc -o test1 dominion.c unittest1.c rngs.c interface.c -lm -coverage

test2: dominion.c unittest2.c rngs.c interface.c
	gcc -o test2 dominion.c unittest2.c rngs.c interface.c -lm -coverage

test3: dominion.c unittest3.c rngs.c interface.c
	gcc -o test3 dominion.c unittest3.c rngs.c interface.c -lm -coverage

test4: dominion.c unittest4.c rngs.c interface.c
	gcc -o test4 dominion.c unittest4.c rngs.c interface.c -lm -coverage

cardt1: dominion.c cardtest1.c rngs.c interface.c
	gcc -o card1 dominion.c cardtest1.c  rngs.c interface.c -lm -coverage

cardt2: dominion.c cardtest2.c rngs.c interface.c
	gcc -o card2 dominion.c cardtest2.c  rngs.c interface.c -lm -coverage

cardt3: dominion.c cardtest3.c rngs.c interface.c
	gcc -o card3 dominion.c cardtest3.c  rngs.c interface.c -lm -coverage

cardt4: dominion.c cardtest4.c rngs.c interface.c
	gcc -o card4 dominion.c cardtest4.c  rngs.c interface.c -lm -coverage

pretest: unittest1.c unittest2.c unittest3.c unittest4.c
	touch unittest1.c
	touch unittest2.c
	touch unittest3.c
	touch unittest4.c
	touch cardtest1.c
	touch cardtest2.c
	touch cardtest3.c
	touch cardtest4.c
	> unittestresults.out

runtests: test1 test2 test3 test4 cardt1 cardt2 cardt3 cardt4
	test1
	chmod +w unittestresults.out
	gcov unittest1.c -b >> unittestresults.out
	test2
	gcov unittest2.c -b >> unittestresults.out
	test3
	gcov unittest3.c -b >> unittestresults.out
	test4
	gcov unittest4.c -b >> unittestresults.out
	card1
	gcov cardtest1.c -b >> unittestresults.out
	card2
	gcov cardtest2.c -b >> unittestresults.out
	card3
	gcov cardtest3.c -b >> unittestresults.out
	card4
	gcov cardtest4.c -b >> unittestresults.out
	echo "Dominion Coverage:" >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out