#ifndef INTEGER_SET_CPP
#define INTEGER_SET_CPP

#include "IntegerSet.h"
#include <iostream>
#include <string>
using namespace std;

IntegerSet::IntegerSet() {
	for (int i = 0; i <= 100; i++)
		integerSet.push_back(false);
}

IntegerSet::IntegerSet(int arr[], int size) {
	for (int i = 0; i <= 100; i++)
		integerSet.push_back(false);

	for (int i = 0; i < size; i++) {
		insertElement(arr[i]);
	}
}

void IntegerSet::inputSet() {
	int input;
	string buf;
	while (true) {
		cout << "Enter an element (-1 to end): ";
		getline(cin, buf);
		input = atoi(buf.c_str());

		if (input == -1)
			break;
		else
			insertElement(input);
	}
}

IntegerSet IntegerSet::unionOfSets(IntegerSet other) {
	IntegerSet newSet;
	for (int i = 0; i <= 100; i++) {
		if (integerSet[i] || other.integerSet[i]) {
			newSet.insertElement(i);
		}
	}
	return newSet;
}

IntegerSet IntegerSet::intersectionOfSets(IntegerSet other) {
	IntegerSet newSet;
	for (int i = 0; i <= 100; i++) {
		if (integerSet[i] && other.integerSet[i]) {
			newSet.insertElement(i);
		}
	}
	return newSet;
}

bool IntegerSet::isEqualTo(IntegerSet other) {
	for (int i = 0; i <= 100; i++) {
		if (integerSet[i] != other.integerSet[i])
			return false;
	}

	return true;
}

void IntegerSet::printSet() {
	cout << "{  ";
	for (int i = 0; i <= 100; i++) {
		if (integerSet[i])
			cout << i << "  ";
	}
	cout << "}" << endl;
}

void IntegerSet::insertElement(int element) {
	if (element < 0 || element > 100) {
		cout << "Invalid insert attempted!" << endl;
	}
	else {
		integerSet[element] = true;
	}
}

void IntegerSet::deleteElement(int element) {
	if (element >= 0 && element <= 100) {
		integerSet[element] = false;
	}
}

#endif