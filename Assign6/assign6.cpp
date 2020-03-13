#ifndef ASSIGN6_CPP
#define ASSIGN6_CPP

#include "DeckOfCards.hpp"
#include <iostream>

int main() {
  DeckOfCards deck = DeckOfCards();
  deck.shuffle();

  int count = 1;
  while (deck.moreCards()) {
    std::cout.width(20);
    std::cout << deck.dealCard().toString();
    if (count++ % 4 == 0) {
      std::cout << std::endl;
    }
  }

  return 0;
}

#endif //ASSIGN6_CPP