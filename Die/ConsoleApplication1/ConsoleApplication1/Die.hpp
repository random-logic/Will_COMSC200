#ifndef DIE_HPP
#define DIE_HPP

class Die {
  private:
    int sides, value;

  public:
    Die(int numSides);

    void setSides(int numSides);

    void roll();

    int getSides();
    
    int getValue();
};

#endif