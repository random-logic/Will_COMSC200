#ifndef DECK_OF_CARDS_CPP
#define DECK_OF_CARDS_CPP

#include "DeckOfCards.hpp"

DeckOfCards::DeckOfCards() {
  //Get the system time
  time_t seed = time(0);
  //Seed the random number generator
  srand(static_cast<int>(seed));
}

void DeckOfCards::shuffle() {
  std::vector<Card> temp;
  //Use rand() to return a random int from 0 to the max int
}

Card dealCard() {
}

bool moreCards() {
}

#endif //DECK_OF_CARDS_CPP