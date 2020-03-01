#ifndef ODOMETER_CPP
#define ODOMETER_CPP

#include "Odometer.hpp"

Odometer::Odometer(FuelGauge *_fuelGauge) {
  milage = 0;
  fuelGauge = _fuelGauge;
}

int Odometer::getMilage() {
}

void Odometer::addMile() {
}

Odometer::~Odometer() {
  delete fuelGauge;
}

#endif //ODOMETER_CPP