#ifndef ODOMETER_HPP
#define ODOMETER_HPP

#include "FuelGauge.hpp"

class Odometer {
  private:
    int milage;
    FuelGauge *fuelGauge;
  public:
    Odometer(FuelGauge *_fuelGauge);
    int getMilage();
    void addMile();
    ~Odometer();
};

#endif //ODOMETER_HPP