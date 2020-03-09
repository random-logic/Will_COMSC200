#ifndef FUELGAUGE_CPP
#define FUELGAUGE_CPP

#include "FuelGauge.hpp"

FuelGauge::FuelGauge() {
  gallons_of_fuel = 0;
}

void FuelGauge::add1Gal() {
  if (gallons_of_fuel < 15) {
    gallons_of_fuel++;
  }
}

void FuelGauge::dec1Gal() {
  if (gallons_of_fuel > 0) {
    gallons_of_fuel--;
  }
}

int FuelGauge::getGallons() {
  return gallons_of_fuel;
}

#endif //FUELGAUGE_CPP