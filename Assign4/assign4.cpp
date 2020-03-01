#ifndef ASSIGN4
#define ASSIGN4

#include "HeartRates.hpp"
#include <iostream>

int main () {
  string first_name, last_name, buf;
  cout << "Please enter first and last name (separated by spaces):" << endl;
  cin >> first_name >> last_name;
  int month, day, year;
  cout << "Please enter month, day, and year of birth (seperated by spaces):" << endl;
  cin >> buf;
  month = atoi(buf.c_str()); //Getting input as string and then converting to an int so the program does not crash if user inputs letters as int
  cin >> buf;
  day = atoi(buf.c_str());
  cin >> buf;
  year = atoi(buf.c_str());
  HeartRates heartRates = HeartRates(first_name, last_name, month, day, year);
  cout << "Please enter today's month, day, and year (separated by spaces):" << endl;
  cin >> buf;
  month = atoi(buf.c_str());
  cin >> buf;
  day = atoi(buf.c_str());
  cin >> buf;
  year = atoi(buf.c_str());
  cout << "Current Age: " << heartRates.getAge(month, day, year) << endl;
  cout << "Max Heart Rate: " << heartRates.getMaximumHeartRate(month, day, year) << endl;
  cout << "Target Heart Rate: " << heartRates.getTargetHeartRate(month, day, year) << endl;
  return 0;
}

#endif //ASSIGN4