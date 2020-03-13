#ifndef CARD_HPP
#define CARD_HPP

#include <string>

class Card {
  private:
    int face;
    int suit;
    const static std::string faces[];
    const static std::string suits[];
  public:
    Card(int _face, int _suit);
    std::string toString();
};

#endif //CARD_HPP