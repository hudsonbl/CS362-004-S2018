CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

randomtests: randomtest1.c randomtest2.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o
	gcc -o randomtest1 -g randomtest1.c dominion.o rngs.o $(CFLAGS)
	gcc -o randomtest2 -g randomtest2.c dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest1   -g cardtest1.c dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest2   -g cardtest2.c dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest3   -g cardtest3.c dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest4   -g cardtest4.c dominion.o rngs.o $(CFLAGS)

concluderandtest1: randomtest1
	./randomtest1 &> randomtest1.out
	gcov randomtest1.c >> randomtest1.out
	cat randomtest1.c.gcov >> randomtest1.out

concluderandtest2: randomtest2
	./randomtest2 &> randomtest2.out
	gcov randomtest2.c >> randomtest2.out
	cat randomtest2.c.gcov >> randomtest2.out

concludetest1: cardtest1
	./cardtest1 &> cardtest1.out
	gcov cardtest1.c >> cardtest1.out
	cat cardtest1.c.gcov >> cardtest1.out

concludetest2: cardtest2
	./cardtest2 &> cardtest2.out
	gcov cardtest2.c >> cardtest2.out
	cat cardtest2.c.gcov >> cardtest2.out

concludetest3: cardtest3
	./cardtest3 &> cardtest3.out
	gcov cardtest3.c >> cardtest3.out
	cat cardtest3.c.gcov >> cardtest3.out

concludetest4: cardtest4
	./cardtest4 &> cardtest4.out
	gcov cardtest4.c >> cardtest4.out
	cat cardtest4.c.gcov >> cardtest4.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
