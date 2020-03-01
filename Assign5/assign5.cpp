#ifndef ASSIGN5
#define ASSIGN5

#include "Odometer.hpp"
#include <iostream>
using namespace std;

int main() {
  FuelGauge fuelGauge = FuelGauge();
  Odometer odo = Odometer(&fuelGauge);

  while (fuelGauge.getGallons() != 0)
    cout << "Mileage: " << odo.getMilage << endl
        << "Fuel Level: " << fuelGauge.getGallons() << " gallons" << endl
        << "----------------------------------------------------" << endl;
  
  cout << "Mileage: " << odo.getMilage << endl
    << "Fuel Level: " << fuelGauge.getGallons() << " gallons" << endl
    << "----------------------------------------------------" << endl;
    
  return 0;
}

#endif //ASSIGN5