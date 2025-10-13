#pragma once
#include "Vehicle.h"

class Car : public Vehicle{
    private:
    int numDoors;
    bool isElectric;

    public:

    Car();

    Car(std::string make, std::string model, int year, double mileage, int numDoors, bool isElectric);

    virtual ~Car() override ;

    bool isElectricCar() const;

    void setNumDoors(int numDoors);

    int getNumDoors() const;

    double getFuelEfficiency() const override;

    void displayInfo() const override;

};