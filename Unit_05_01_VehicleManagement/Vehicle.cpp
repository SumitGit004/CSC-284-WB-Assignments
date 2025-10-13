#include "Vehicle.h"
#include <print>

int Vehicle::vehicleCount = 0;

Vehicle::Vehicle():Vehicle("", "", 0, 0){}

Vehicle::Vehicle(std::string make, std::string model, int year, double mileage)
    : make{make}, model{model} {

     this->year = (year < 0) ?  0 : year;

    this->mileage = (mileage < 0) ?  0 : mileage;
    
    vehicleCount++;
};

Vehicle::~Vehicle() {
  std::print("{} {} {} has been destroyed in Vehicle Class\n\n",year,make, model);
}

std::string Vehicle::getMake() const {
     return make;
}

void Vehicle::setMake(std::string make){
    this->make = make;
}

std::string Vehicle::getModel() const{
   return model;
}

void Vehicle::setModel(std::string model){
   this->model = model;
}

int Vehicle::getYear() const{
    return year;
}

void Vehicle::setYear(int year){
    if(year < 0)
    this->year = 0;

}

double Vehicle::getMileage() const{
    return mileage;
}

void Vehicle::setMileage(double mileage){
    if (mileage >= 0)
    this->mileage = mileage;
}

void Vehicle::displayInfo() const{
 std::println("{} {} {} | Mileage: {} km",year,make, model, mileage);
}

int Vehicle::getVehicleCount(){
    return vehicleCount;
}

