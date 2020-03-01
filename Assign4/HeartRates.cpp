#ifndef HEARTRATES_CPP
#define HEARTRATES_CPP

#include "HeartRates.hpp"

HeartRates::HeartRates (string _first_name, string _last_name, int _mo_birth, int _day_birth, int _yr_birth) {
  first_name = _first_name;
  last_name = _last_name;
  mo_birth = _mo_birth;
  day_birth = _day_birth;
  yr_birth = _yr_birth;
}

int getAge() {
}

double getMaximumHeartRate() {
}

double getTargetHeartRate() {
}

#endif //HEARTRATES_CPP