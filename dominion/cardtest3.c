
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


//======================================Test Council Room=============================================

void caseCouncilRoom(int currentPlayer, struct gameState *state, int handPos) {
	//+4 Cards
	//--------------Input Gathering------------------
	int numCardsBefore = state->deckCount[currentPlayer];
	int i;
	for (i = 0; i < 4; i++)
	{
		drawCard(currentPlayer, state);
	}
	int numCardsAfter = state->deckCount[currentPlayer];
	//+1 Buy
	int numberBuysBefore = state->numBuys;
	state->numBuys++;
	int numberBuysAfter = state->numBuys;
	printf("------------Testing Council Room Buys-----------------\n");
	printf("Room Buys before %d compared to after %d\n", numberBuysBefore, numberBuysAfter);

	//Each other player draws a card
	for (i = 0; i < state->numPlayers; i++)
	{
		if (i != currentPlayer)
		{
			drawCard(i, state);
		}
	}

	//put played card in played card pile
	discardCard(handPos, currentPlayer, state, 0);
	int numCardsAfterDiscard = state->deckCount[currentPlayer];
	printf("------------Testing Council Room-----------------\n");
	printf("Deck before card draw %d compared to after but before council card is discarded %d\n", numCardsBefore, numCardsAfter);
	printf("Deck after discard %d\n", numCardsAfterDiscard);
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

	caseCouncilRoom(0, &gstate, 0);

	return 0;
}