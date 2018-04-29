
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


//======================================Test Village=============================================

void caseVillage(int currentPlayer, struct gameState *state, int handPos) {
	//--------------Gathering Inputs------------------------
	//+1 Card

	int numCardsBefore = state->deckCount[currentPlayer];
	drawCard(currentPlayer, state);
	int numCardsAfter = state->deckCount[currentPlayer];
	//+2 Actions

	//----------------Gathering Inputs-------------------------
	int numActionsBefore = state->numActions;
	state->numActions = state->numActions + 2;
	int numActionsAfter = state->numActions;

	printf("------------Testing Village Actions-----------------\n");
	printf("Deck before actions %d compared to after %d\n", numActionsBefore, numActionsAfter);

	//discard played card from hand
	discardCard(handPos, currentPlayer, state, 0);
	int numCardsAfterDiscard = state->deckCount[currentPlayer];
	printf("------------Testing Village Card Draws-----------------\n");
	printf("Deck before card draw %d compared to after but before smithy card is discarded %d\n", numCardsBefore, numCardsAfter);
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