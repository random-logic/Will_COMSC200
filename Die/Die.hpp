#ifndef HPP
#define HPP

#include <cstdlib>
#include <ctime>
using namespace std;

class Die {
  private:
    int sides, value;

  public:
    explicit Die(int numSides) {
      sides = numSides;
      value = 0;
	  //Get the system time
	  time_t seed = time(0);
	  //Seed the random number generator
	  srand(static_cast<int>(seed));
    }

    void setSides(int numSides) {
      sides = numSides;
    }

    void roll() {
      value = rand() % sides + 1;
    }

    int getSides() {
      return sides;
    }
    
    int getValue() {
      return value;
    }
};

#endif