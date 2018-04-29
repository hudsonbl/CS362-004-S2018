#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int getCost(int cardNumber)
{
	switch (cardNumber)
	{
	case curse:
		return 0;
	case estate:
		return 2;
	case duchy:
		return 5;
	case province:
		return 8;
	case copper:
		return 0;
	case silver:
		return 3;
	case gold:
		return 6;
	case adventurer:
		return 6;
	case council_room:
		return 5;
	case feast:
		return 4;
	case gardens:
		return 4;
	case mine:
		return 5;
	case remodel:
		return 4;
	case smithy:
		return 4;
	case village:
		return 3;
	case baron:
		return 4;
	case great_hall:
		return 3;
	case minion:
		return 5;
	case steward:
		return 3;
	case tribute:
		return 5;
	case ambassador:
		return 3;
	case cutpurse:
		return 4;
	case embargo:
		return 2;
	case outpost:
		return 5;
	case salvager:
		return 4;
	case sea_hag:
		return 4;
	case treasure_map:
		return 4;
	}

	return -1;
}

int main() {
	
	//This unit test will test the getCost function
	//Using the enum values provided in dominion.h
	
	assert(0 == getCost(curse));
	printf("Test for curse worked!\n");
	assert(2 == getCost(estate));
	printf("Test for estate worked!\n");
	assert(5 == getCost(duchy));
	printf("Test for duchy worked!\n");
	assert(8 == getCost(province));
	printf("Test for province worked!\n");
	assert(0 == getCost(copper));
	printf("Test for copper worked!\n");
	assert(3 == getCost(silver));
	printf("Test for silver worked!\n");
	assert(6 == getCost(gold));
	printf("Test for gold worked!\n");
	assert(6 == getCost(adventurer));
	printf("Test for adventurer worked!\n");
	assert(5 == getCost(council_room));
	printf("Test for council_room worked!\n");
	assert(4 == getCost(feast));
	printf("Test for feast worked!\n");
	assert(4 == getCost(gardens));
	printf("Test for gardens worked!\n");
	assert(5 == getCost(mine));
	printf("Test for mine worked!\n");
	assert(4 == getCost(remodel));
	printf("Test for remodel worked!\n");
	assert(4 == getCost(smithy));
	printf("Test for smithy worked!\n");
	assert(3 == getCost(village));
	printf("Test for village worked!\n");
	assert(4 == getCost(baron));
	printf("Test for baron worked!\n");
	assert(3 == getCost(great_hall));
	printf("Test for great_hall worked!\n");
	assert(5 == getCost(minion));
	printf("Test for minion worked!\n");
	assert(3 == getCost(steward));
	printf("Test for steward worked!\n");
	assert(5 == getCost(tribute));
	printf("Test for tribute worked!\n");
	assert(3 == getCost(ambassador));
	printf("Test for ambassador worked!\n");
	assert(4 == getCost(cutpurse));
	printf("Test for cutpurse worked!\n");
	assert(2 == getCost(embargo));
	printf("Test for embargo worked!\n");
	assert(5 == getCost(outpost));
	printf("Test for outpost worked!\n");
	assert(4 == getCost(salvager));
	printf("Test for salvager worked!\n");
	assert(4 == getCost(sea_hag));
	printf("Test for sea_hag worked!\n");
	assert(4 == getCost(treasure_map));
	printf("Test for treasure_map worked!\n");


	return 0;
}