#ifndef ASSIGN5
#define ASSIGN5

#include "Odometer.hpp"
#include <iostream>
using namespace std;

int main() {
  FuelGauge fuelGauge = FuelGauge();
  Odometer odo = Odometer(&fuelGauge);

  //Add a total of 15 gallons of fuel
  for (int i = 0; i < 15; i++) {
    fuelGauge.add1Gal();
  }

  while (fuelGauge.getGallons() > 0) {
    odo.addMile();
    cout << "Mileage: " << odo.getMileage() << endl
         << "Fuel Level: " << fuelGauge.getGallons() << " gallons" << endl
         << "----------------------------------------------------" << endl;
  }
    
  return 0;
}

#endif //ASSIGN5