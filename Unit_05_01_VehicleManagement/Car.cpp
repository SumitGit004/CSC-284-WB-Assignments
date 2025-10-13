#include "Car.h"
#include <print>

Car::Car() : numDoors{1}, isElectric{false} {}

Car::Car(std::string make, std::string model, int year, double mileage, int numDoors, bool isElectric)
     : Vehicle(make, model, year, mileage), isElectric{isElectric} {
   
      this->numDoors  = (numDoors < 1) ? 1 : numDoors;
}

Car::~Car(){
    std::print("Destructor for car is called from Car class\n");
}

void Car::setNumDoors(int numDoors) {
    this->numDoors = numDoors;
}

int Car::getNumDoors() const{
    return numDoors;
}

bool Car::isElectricCar() const{
    return isElectric;
}

//returns fuel efficiency of a car in kilometer per litre.
double Car::getFuelEfficiency() const{

    return (isElectric ? 0 : 31);
}

void Car::displayInfo() const{

    Vehicle::displayInfo();
    std::println("Type: Car | Doors: {} | Electric: {}",numDoors,(isElectric ? "Yes" : "No"));
    std::println("Fuel Efficiency: {} km/l\n", getFuelEfficiency());
}