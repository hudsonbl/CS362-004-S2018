#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int shuffle(int player, struct gameState *state) {

	int newDeck[MAX_DECK];
	int newDeckPos = 0;
	int card;
	int i;
	
	if (state->deckCount[player] < 1)
		return -1;
	qsort((void*)(state->deck[player]), state->deckCount[player], sizeof(int), compare);
	/* SORT CARDS IN DECK TO ENSURE DETERMINISM! */
	//-------------Gathering Input---------------------
	int TESTCOINS = state->coins;
	printf("------------First Test---- Coins--------\n")
	printf("          Coins: %d         \n"l, TESTCOINS);



	while (state->deckCount[player] > 0) {
		card = floor(Random() * state->deckCount[player]);
		newDeck[newDeckPos] = state->deck[player][card];
		newDeckPos++;
		for (i = card; i < state->deckCount[player] - 1; i++) {
			state->deck[player][i] = state->deck[player][i + 1];
		}
		state->deckCount[player]--;
	}
	for (i = 0; i < newDeckPos; i++) {
		state->deck[player][i] = newDeck[i];
		state->deckCount[player]++;
	}
	printf("-------------Second Test------The Cards are truely shuffled--------\n")
	printf("Testing first card: %d", state->deck[0][card]);
	printf("\n\
		    \n");
	printf("This will be ran multiple times to ensure that the first case is different. \n\
		     I am using basic analysis implying if p is true then p+1 is also true. \n\
			In this case I am implying that the rest of the cards are most likely shuffled\n");

	int TESTDECKCOUNT = state->deckCount[player];
	printf("-----------------Third Test----------------\n");
	printf("          Deck Count: %d    Should be: 500", TESTDECKCOUNT);
	assert(TESTDECKCOUNT == 500);
	return 0;
}

int main() {

	int newCards = 0;
	int discarded = 1;
	int xtraCoins = 0;
	int shuffledCards = 0;

	int i, j, m;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int remove1, remove2;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };


	initializeGame(numPlayers, k, seed, &testG);

	shuffle(0, &testG);

	return 0; 
}