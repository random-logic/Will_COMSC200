#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <vector>

class RationalNumber {
private:
	int numerator, denominator;
	static int gcd(int, int);
	void simplify();

public:
	RationalNumber();
	RationalNumber(int);
	RationalNumber(int, int);

	RationalNumber operator + (RationalNumber other) const;
	RationalNumber operator - (RationalNumber other) const;
	RationalNumber operator * (RationalNumber other) const;
	RationalNumber operator / (RationalNumber other) const;
	bool operator < (RationalNumber other) const;
	bool operator > (RationalNumber other) const;
	bool operator <= (RationalNumber other) const;
	bool operator >= (RationalNumber other) const;
	bool operator == (RationalNumber other) const;
	bool operator != (RationalNumber other) const;
	RationalNumber& operator = (RationalNumber other);

	void printRational() const;
};

#endif //RATIONALNUMBER_H