#ifndef COIN_CPP
#define COIN_CPP

#include <cstdlib>
#include <ctime>
#include "Coin.hpp"
using namespace std;

Coin::Coin() {
	sideUp = "Heads";
	//Get the system time
	time_t seed = time(0);
	//Seed the random number generator
	srand(static_cast<int>(seed));
}

void Coin::toss() {
	int random = rand() % 2;
	if (random)
		sideUp = "Heads";
	else
		sideUp = "Tails";
}

string Coin::getSideUp() const {
	return sideUp;
}

#endif