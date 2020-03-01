#ifndef FUELGAUGE_HPP
#define FUELGAUGE_HPP

class FuelGauge {
  private:
    int gallons_of_fuel;
  public:
    FuelGauge();
    void add1Gal();
    void dec1Gal();
    int getGallons();
};

#endif //FUELGAUGE_HPP