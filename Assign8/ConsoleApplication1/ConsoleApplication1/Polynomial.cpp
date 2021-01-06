#ifndef POLYNOMIAL_CPP
#define POLYNOMIAL_CPP

#include "Polynomial.h"
#include <iostream>
using namespace std;

void Polynomial::swapTerms(int i, int j) {
	int tempCoefficient = this->coefficients[i];
	int tempExponent = this->exponents[i];
	this->coefficients[i] = this->coefficients[j];
	this->exponents[i] = this->exponents[j];
	this->coefficients[j] = tempCoefficient;
	this->exponents[j] = tempExponent;
}

void Polynomial::sortTerms() {
	for (int i = 0; i < this->exponents.size(); i++)
		for (int j = i + 1; j < this->exponents.size(); j++) {
			if (this->exponents[j] > this->exponents[i]) {
				this->swapTerms(i, j);
			}
		}
}

void Polynomial::cleanUp() {
	vector<int> newCoefficients, newExponents;
	
	for (int i = 0; i < this->coefficients.size(); i++) {
		if (coefficients[i] != 0) {
			newCoefficients.push_back(this->coefficients[i]);
			newExponents.push_back(this->exponents[i]);
		}
	}

	this->coefficients = newCoefficients;
	this->exponents = newExponents;
}

string Polynomial::getPolynomial() const {
	if (this->exponents.size() == 0) {
		return to_string(0);
	}
	
	string str = "";

	for (int i = 0; i < this->exponents.size(); i++) {
		if (this->coefficients[i] >= 0 && i != 0) {
			str += "+";
		}

		if (this->exponents[i] == 0) {
			str += to_string(this->coefficients[i]);
		}
		else if (this->exponents[i] == 1) {
			str += to_string(this->coefficients[i]) + "x";
		}
		else {
			str += to_string(this->coefficients[i]) + "x^" + to_string(this->exponents[i]);
		}
	}

	return str;
}

void Polynomial::enterTerms() {
	string buf;
	cout << "Enter number of polynomial terms: ";
	getline(cin, buf);
	int terms = atoi(buf.c_str());

	cout << endl;

	for (int i = 0; i < terms; i++) {
		cout << "Enter coefficient: ";
		getline(cin, buf);
		this->coefficients.push_back(atoi(buf.c_str()));
		cout << "Enter exponents: ";
		getline(cin, buf);
		this->exponents.push_back(atoi(buf.c_str()));
		cout << endl;
	}

	this->sortTerms();
}

void Polynomial::printPolynomial() const {
	cout << getPolynomial();
}

Polynomial Polynomial::operator + (const Polynomial& other) const {
	Polynomial newPolynomial = *this;
	newPolynomial += other;
	return newPolynomial;
}

Polynomial Polynomial::operator - (const Polynomial& other) const {
	Polynomial newPolynomial = *this;
	newPolynomial -= other;
	return newPolynomial;
}

Polynomial& Polynomial::operator += (const Polynomial& other) {
	Polynomial newPolynomial;
	int i = 0, j = 0;

	while (i < this->exponents.size() && j < other.exponents.size()) {
		if (this->exponents[i] > other.exponents[j]) {
			newPolynomial.exponents.push_back(this->exponents[i]);
			newPolynomial.coefficients.push_back(this->coefficients[i]);
			i++;
		}
		else if (this->exponents[i] == other.exponents[j]) {
			newPolynomial.exponents.push_back(this->exponents[i]);
			int newCoefficient = this->coefficients[i] + other.coefficients[j];
			newPolynomial.coefficients.push_back(newCoefficient);
			i++;
			j++;
		}
		else /*if (this->exponents[i] < other.exponents[j])*/ {
			newPolynomial.exponents.push_back(other.exponents[j]);
			newPolynomial.coefficients.push_back(other.coefficients[j]);
			j++;
		}
	}

	while (i < this->exponents.size()) {
		newPolynomial.exponents.push_back(this->exponents[i]);
		newPolynomial.coefficients.push_back(this->coefficients[i]);
		i++;
	}

	while (j < this->exponents.size()) {
		newPolynomial.exponents.push_back(other.exponents[j]);
		newPolynomial.coefficients.push_back(other.coefficients[j]);
		j++;
	}

	*this = newPolynomial;
	this->cleanUp();
	return *this;
}

Polynomial& Polynomial::operator -= (const Polynomial& other) {
	Polynomial minusOther = other;

	for (int i = 0; i < other.exponents.size(); i++) {
		minusOther.coefficients[i] = -1 * minusOther.coefficients[i];
	}

	*this += minusOther;
	return *this;
}

Polynomial& Polynomial::operator = (const Polynomial& other) {
	this->coefficients = other.coefficients;
	this->exponents = other.exponents;
	return *this;
}

#endif //POLYNOMIAL_CPP