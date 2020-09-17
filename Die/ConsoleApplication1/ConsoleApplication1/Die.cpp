#ifndef DIE_CPP
#define DIE_CPP

#include <cstdlib>
#include <ctime>
#include "Die.hpp"

using namespace std;

Die::Die(int numSides) {
	sides = numSides;
	value = 0;
	//Get the system time
	time_t seed = time(0);
	//Seed the random number generator
	srand(static_cast<int>(seed));
}

void Die::setSides(int numSides) {
	sides = numSides;
}

void Die::roll() {
	value = rand() % sides + 1;
}

int Die::getSides() {
	return sides;
}

int Die::getValue() {
	return value;
}

#endif