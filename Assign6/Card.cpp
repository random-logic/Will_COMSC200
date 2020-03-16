#ifndef CARD_CPP
#define CARD_CPP

#include "Card.hpp"

const std::string Card::faces[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Jack", "Queen", "King"};
const std::string Card::suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

Card::Card(int _face, int _suit) {
  face = _face;
  suit = _suit;
}

std::string Card::toString() {
  return faces[face] + " of " + suits[suit];
}

#endif //CARD_CPP