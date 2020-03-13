#ifndef DECK_OF_CARDS_HPP
#define DECK_OF_CARDS_HPP

#include "Card.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

class DeckOfCards {
  private:
    std::vector<Card> deck;
    int currentCard;
  public:
    DeckOfCards();
    void shuffle();
    Card dealCard();
    bool moreCards();
};

#endif //DECK_OF_CARDS_HPP