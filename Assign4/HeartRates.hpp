#ifndef HEARTRATES_HPP
#define HEARTRATES_HPP

#include <string>
using namespace std;

class HeartRates {
  private:
    string first_name, last_name;
    int mo_birth, day_birth, yr_birth;
  public:
    HeartRates(string _first_name, string _last_name, int _mo_birth, int _day_birth, int _yr_birth);
    int getAge(int current_mo, int current_day, int current_yr);
    int getMaximumHeartRate(int current_mo, int current_day, int current_yr);
    string getTargetHeartRate(int current_mo, int current_day, int current_yr);
    void doSomethingForConstructor(); //DELETE
};

#endif //HEARTRATES_HPP