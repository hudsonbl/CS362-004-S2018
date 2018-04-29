#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int updateCoins(int player, struct gameState *state, int bonus)
{
	int i;
	
	//reset coin count
	state->coins = 0;

	//add coins for each Treasure card in player's hand
	for (i = 0; i < state->handCount[player]; i++)
	{
		printf("---------Test----------------\n");
		printf("Currency Type: %d\n", state->hand[player][i]);
		if (state->hand[player][i] == copper)
		{
			assert(state->hand[player][i] == copper);
			state->coins += 1;
		}
		else if (state->hand[player][i] == silver)
		{
			assert(state->hand[player][i] == silver);
			state->coins += 2;
		}
		else if (state->hand[player][i] == gold)
		{
			assert(state->hand[player][i] == gold);
			state->coins += 3;
		}
	}
	int countCoins = state->coins;
	printf("----------Test----------------\n");
	printf("coin count: %d\n", countCoins);
	

	printf("-----------------Test-----Treasure map adds extra coins----------\n");
	for (i = 0; i < state->handCount[player]; i++) {
		if (state->hand[player][i] == treasure_map)
			printf("Found Treasure map\n");
	}
	//add bonus
	state->coins += bonus;

	return 0;
}

int main() {

	int newCards = 0;
	int discarded = 1;
	int xtraCoins = 0;
	int shuffledCards = 0;
	int testBonus = 0;

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

	updateCoins(0, &testG, testBonus);

	return 0;
}