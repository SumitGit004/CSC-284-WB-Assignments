#pragma once
#include "Vehicle.h"

class Truck : public Vehicle{
    private:
    double loadCapacity;

    public:
    
    Truck();

    Truck(std::string make, std::string model, int year, double mileage, double loadCapacity);

    virtual ~Truck() override ;

    double getFuelEfficiency() const override;

    void displayInfo() const override;
};