#ifndef ODOMETER_HPP
#define ODOMETER_HPP

#include "FuelGauge.hpp"

class Odometer {
  private:
    int mileage;
    FuelGauge *fuelGauge;
  public:
    Odometer(FuelGauge *_fuelGauge);
    int getMileage();
    void addMile();
    ~Odometer();
};

#endif //ODOMETER_HPP