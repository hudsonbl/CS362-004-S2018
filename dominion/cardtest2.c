#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


//======================================Test Adventurer=============================================
void caseAdventurer(int drawntreasure, struct gameState *state, int currentPlayer, int temphand[MAX_HAND], int z) {
	
	//--------------------------Input Gathering-------------------------------
	int numCardsBefore = state->deckCount[currentPlayer];
	int cardDrawn;
	while (drawntreasure<2) {


		if (state->deckCount[currentPlayer] <1) {//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else {
			temphand[z] = cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	//-----------------------Input Gathering--------------------
	numCardsAfter = state->deckCount[currentPlayer];


	while (z - 1 >= 0) {
		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
		z = z - 1;
	}
	//------------------------Input Gathering------------------

	int numCardsAfterDiscard = state->deckCount[currentPlayer];
	printf("------------Testing Smithy-----------------\n");
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

	caseAdventurer(0, &testG, currentPlayer, temphand, 0);

	return 0;
}