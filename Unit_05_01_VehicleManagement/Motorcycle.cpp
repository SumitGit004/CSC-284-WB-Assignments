#include "Motorcycle.h"
#include <print>


Motorcycle::Motorcycle():hasSideCar(false){}

Motorcycle::~Motorcycle() {
    std::print("Destructor for motorcycle is called from Motorcycle Class\n");
}

Motorcycle::Motorcycle(std::string make,std::string model, int year, double mileage,bool hasSideCar)
       : Vehicle(make, model, year, mileage), hasSideCar(hasSideCar) {}

bool Motorcycle::isThereSideCar() const{
    return hasSideCar;
}

//returns fuel efficiency in kilomter per litre
double Motorcycle::getFuelEfficiency() const{
    return 40;
}

void Motorcycle::displayInfo() const {
    Vehicle::displayInfo();
     std::println("Type: Motorcycle | Sidecar: {}", (hasSideCar ? "Yes" : "No"));
     std::println("Fuel Efficiency: {} km/l\n", getFuelEfficiency());
}