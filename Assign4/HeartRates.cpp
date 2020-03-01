#ifndef HEARTRATES_CPP
#define HEARTRATES_CPP

#include "HeartRates.hpp"
#include <iostream> //DELETE

HeartRates::HeartRates (string _first_name, string _last_name, int _mo_birth, int _day_birth, int _yr_birth) {
  first_name = _first_name;
  last_name = _last_name;
  mo_birth = _mo_birth;
  day_birth = _day_birth;
  yr_birth = _yr_birth;
  doSomethingForConstructor(); //DELETE
}

int HeartRates::getAge(int current_mo, int current_day, int current_yr) {
  int years = current_yr - yr_birth;
  if (current_mo < mo_birth) {
    years--;
  }
  else if (current_mo == mo_birth && current_day < day_birth) {
    years--;
  }
  return years;
  //Math way of calculating instead
  //static_cast<double> casting int to double to perform double division not int division
  /*double current_years = current_yr + static_cast<double>(current_mo) / 12 + static_cast<double>(current_day) / 365;
  double birth_year = yr_birth + static_cast<double>(mo_birth) / 12 + static_cast<double>(current_day) / 365;
  return static_cast<int>(current_years - birth_year);*/
}

int HeartRates::getMaximumHeartRate(int current_mo, int current_day, int current_yr) {
  return 220 - getAge(current_mo, current_day, current_yr);
}

string HeartRates::getTargetHeartRate(int current_mo, int current_day, int current_yr) {
  return "" + to_string(static_cast<int>(0.5 * getMaximumHeartRate(current_mo, current_day, current_yr) + 0.5)) 
      + "-" + to_string(static_cast<int>(0.85 * getMaximumHeartRate(current_mo, current_day, current_yr) + 0.5));
}

//DELETE
void HeartRates::doSomethingForConstructor() {
  cout << "I called a method from a constructor" << endl;
}

#endif //HEARTRATES_CPP