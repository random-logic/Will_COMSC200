#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <string>

class Polynomial {
protected:
	std::vector<int> coefficients;
	std::vector<int> exponents;
	void swapTerms(int, int);
	void sortTerms();
	void cleanUp();
public:
	std::string getPolynomial() const;
	void enterTerms();
	void printPolynomial() const;
	Polynomial operator + (const Polynomial&) const;
	Polynomial operator - (const Polynomial&) const;
	Polynomial& operator += (const Polynomial&);
	Polynomial& operator -= (const Polynomial&);
	Polynomial& operator = (const Polynomial&);
};

#endif //POLYNOMIAL_H