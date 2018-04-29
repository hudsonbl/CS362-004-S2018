#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
{

	
	//if card is not trashed, added to Played pile 
	if (trashFlag < 1)
	{
		//add card to played pile
		state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos];
		state->playedCardCount++;
	}

	//set played card to -1
	state->hand[currentPlayer][handPos] = -1;
	int cardBeingDiscarded = handPos;
	//remove card from player's hand
	if (handPos == (state->handCount[currentPlayer] - 1)) 	//last card in hand array is played
	{

		//reduce number of cards in hand
		state->handCount[currentPlayer]--;
	}
	else if (state->handCount[currentPlayer] == 1) //only one card in hand
	{
		//reduce number of cards in hand
		state->handCount[currentPlayer]--;
	}
	else
	{
		//replace discarded card with last card in hand
		state->hand[currentPlayer][handPos] = state->hand[currentPlayer][(state->handCount[currentPlayer] - 1)];
		//set last card to -1
		state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
		//reduce number of cards in hand
		state->handCount[currentPlayer]--;
	}

	printf("-----------Test----------------\n");
	
	int i;
	for (i = 0; i < state->handCount[currentPlayer]; i++) {
		if (state->hand[currentPlayer][handPos] == state->hand[currentPlayer][cardBeingDiscarded])
			printf("The Card is Still in the deck! Test Failed!\n");
	}
	printf("Otherwise Test Passed if print statement above is not executed!\n");

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

	discardCard(0, 0, &testG, 0);

	return 0;
}