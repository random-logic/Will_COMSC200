#ifndef ASSIGN4
#define ASSIGN4

#include "HeartRates.hpp"
#include <iostream>

int main () {
  string first_name, last_name;
  cout << "Please enter first and last name (separated by spaces):" << endl;
  cin >> first_name >> last_name;
  int month, day, year;
  cout << "Please enter month, day, and year of birth (seperated by spaces):" << endl;
  cin >> month >> day >> year;
  //Create new class object
  cout << "Please enter today's month, day, and year (separated by spaces):" << endl;
  cin >> month >> day >> year;
  //Call getAge method
  //Call other methods
  return 0;
}

#endif //ASSIGN4