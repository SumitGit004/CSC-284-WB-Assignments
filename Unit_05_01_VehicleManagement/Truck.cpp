#include "Truck.h"
#include <print>

Truck::Truck() : loadCapacity{1}{}

Truck::Truck(std::string make, std::string model, int year, double mileage, double loadCapacity)
     : Vehicle(make, model, year, mileage){
   
      this->loadCapacity  = (loadCapacity < 1) ? 1 :loadCapacity;
}

Truck::~Truck() {
     std::print("Destructor for Truck is called from Truck Class\n");
}

//returns truck's fuel efficiency in kilometer/litre
double Truck::getFuelEfficiency() const {
    return 20;
} 

void Truck::displayInfo() const {
     Vehicle::displayInfo();
     std::println("Type: Truck | LoadCapacity: {} tons",loadCapacity);
     std::println("Fuel Efficiency: {} km/l\n", getFuelEfficiency());
}
