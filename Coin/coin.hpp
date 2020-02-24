#ifndef COIN_H
#define COIN_H

#include <string>
using namespace std;

class Coin {
private:
	string sideUp;
public:
	explicit Coin(); //constructor
	void toss(); //method with no return type, so we use void
	string getSideUp() const;
};

#endif