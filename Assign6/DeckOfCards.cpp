#ifndef DECK_OF_CARDS_CPP
#define DECK_OF_CARDS_CPP

#include "DeckOfCards.hpp"

DeckOfCards::DeckOfCards() {
  //Get the system time
  time_t seed = time(0);
  //Seed the random number generator
  srand(static_cast<int>(seed));

  for (int i = 0; i < 13; i++)
    for (int j = 0; j < 4; j++)
      deck.push_back(Card(i, j));
  
  currentCard = 0;
}

void DeckOfCards::shuffle() {
  //Use rand() to return a random int from 0 to the max int
  for (int i = 0; i < deck.size(); i++) {
    int pos = rand() % deck.size() - 1;
    if (pos >= i) pos++;
    Card temp = deck.at(pos);
    deck.at(pos) = deck.at(i);
    deck.at(i) = temp;
  }
  currentCard = 0;
}

Card DeckOfCards::dealCard() {
  return deck.at(currentCard++);
}

bool DeckOfCards::moreCards() {
  return currentCard != deck.size();
}

#endif //DECK_OF_CARDS_CPP