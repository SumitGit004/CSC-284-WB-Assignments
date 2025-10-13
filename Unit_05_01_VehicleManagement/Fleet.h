#pragma once
#include "Vehicle.h"
#include <vector>

class Fleet {
    private:
    std::vector<Vehicle*> fleetList;

    public:

    Fleet() = default;

    ~Fleet();

    void addVehicle(Vehicle* v);

    void displayAllVehicles() const;

    double getAverageEfficiency() const;
};