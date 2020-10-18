#ifndef INTEGER_SET_H
#define INTEGER_SET_H

#include <vector>

class IntegerSet {
private:
	std::vector<bool> integerSet;
public:
	IntegerSet();
	IntegerSet(int arr[], int size);
	void inputSet();
	IntegerSet unionOfSets(IntegerSet other);
	IntegerSet intersectionOfSets(IntegerSet other);
	bool isEqualTo(IntegerSet other);
	void printSet();
	void insertElement(int element);
	void deleteElement(int element);
};

#endif