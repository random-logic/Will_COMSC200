#ifndef RATIONALNUMBER_CPP
#define RATIONALNUMBER_CPP

#include "RationalNumber.h"
#include <iostream>
#include <cmath>
using namespace std;

/*
Find the GCD of two integers using Basic Euclidean algorithm
Algorithm based on facts:
If we subtract smaller number from larger (we reduce larger number), GCD doesn’t change. 
So if we keep subtracting repeatedly the larger of two, we end up with GCD.
Now instead of subtraction, if we divide smaller number, the algorithm stops when we find remainder 0.
*/
int RationalNumber::gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

void RationalNumber::simplify() {
	if (this->denominator < 0) {
		this->numerator *= -1;
		this->denominator *= -1;
	}

	int numerator = this->numerator;
	if (numerator < 0) numerator *= -1;
	int factor = gcd(numerator, this->denominator);

	this->numerator /= factor;
	this->denominator /= factor;
}

RationalNumber::RationalNumber() {
	this->numerator = 0;
	this->denominator = 1;
}

RationalNumber::RationalNumber(int numerator) {
	this->numerator = numerator;
	this->denominator = 1;
}

RationalNumber::RationalNumber(int numerator, int denominator) {
	this->numerator = numerator;
	this->denominator = denominator;
	this->simplify();
}

RationalNumber RationalNumber::operator + (RationalNumber other) const {
	int numerator1 = this->numerator * other.denominator;
	int numerator2 = other.numerator * this->denominator;
	int commonDenominator = this->denominator * other.denominator;

	RationalNumber sum(numerator1 + numerator2, commonDenominator);
	sum.simplify();
	return sum;
}

RationalNumber RationalNumber::operator - (RationalNumber other) const {
	int numerator1 = this->numerator * other.denominator;
	int numerator2 = other.numerator * this->denominator;
	int commonDenominator = this->denominator * other.denominator;

	RationalNumber difference(numerator1 - numerator2, commonDenominator);
	difference.simplify();
	return difference;
}

RationalNumber RationalNumber::operator * (RationalNumber other) const {
	int numerator = this->numerator * other.numerator;
	int denominator = this->denominator * other.denominator;

	RationalNumber product(numerator, denominator);
	product.simplify();
	return product;
}

RationalNumber RationalNumber::operator / (RationalNumber other) const {
	int numerator = this->numerator * other.denominator;
	int denominator = this->denominator * other.numerator;

	RationalNumber quotient(numerator, denominator);
	quotient.simplify();
	return quotient;
}

bool RationalNumber::operator < (RationalNumber other) const {
	int thisNumerator = this->numerator * other.denominator;
	int otherNumerator = other.numerator * this->denominator;

	return thisNumerator < otherNumerator;
}

bool RationalNumber::operator > (RationalNumber other) const {
	int thisNumerator = this->numerator * other.denominator;
	int otherNumerator = other.numerator * this->denominator;

	return thisNumerator > otherNumerator;
}

bool RationalNumber::operator <= (RationalNumber other) const {
	return !(*this > other);
}

bool RationalNumber::operator >= (RationalNumber other) const {
	return !(*this < other);
}

bool RationalNumber::operator == (RationalNumber other) const {
	int thisNumerator = this->numerator * other.denominator;
	int otherNumerator = other.numerator * this->denominator;

	return thisNumerator == otherNumerator;
}

bool RationalNumber::operator != (RationalNumber other) const {
	return !(*this == other);
}

RationalNumber& RationalNumber::operator =(RationalNumber other) {
	this->numerator = other.numerator;
	this->denominator = other.denominator;

	return *this;
}

void RationalNumber::printRational() const {
	if (this->numerator == 0 & this->denominator != 0)
		cout << "0";
	else if (this->denominator == 1)
		cout << this->numerator;
	else
		cout << this->numerator << "/" << this->denominator;
}

#endif //RATIONALNUMBER_CPP