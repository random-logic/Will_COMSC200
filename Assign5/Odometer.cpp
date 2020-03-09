#ifndef ODOMETER_CPP
#define ODOMETER_CPP

#include "Odometer.hpp"

Odometer::Odometer(FuelGauge *_fuelGauge) {
  mileage = 0;
  fuelGauge = _fuelGauge;
}

int Odometer::getMileage() {
  return mileage;
}

void Odometer::addMile() {
  if (mileage < 999999) {
    mileage++;
    if (mileage % 24 == 0) {
      fuelGauge->dec1Gal();
    }
  }
  else {
    mileage = 0;
  }
}

Odometer::~Odometer() {
  delete fuelGauge;
}

#endif //ODOMETER_CPP