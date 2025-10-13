#include "Fleet.h"
#include <print>

Fleet::~Fleet() {
    
    for(Vehicle* vehiclePtr: fleetList) {
        delete vehiclePtr;
    }

     std::println("Fleet has been destroyed\n");
}

void Fleet::addVehicle(Vehicle* vehicle) {
    if(vehicle)
    fleetList.push_back(vehicle);
}

void Fleet::displayAllVehicles() const {
    
    for(const Vehicle* vehiclePtr : fleetList){

       if(vehiclePtr)
       vehiclePtr->displayInfo();
    }
}

double Fleet::getAverageEfficiency() const{

    double totalEfficiency = 0;
    int count = 0;

    for (const Vehicle *vehiclePtr : fleetList){

        if (vehiclePtr){
        totalEfficiency += vehiclePtr->getFuelEfficiency();
        count++;
        }
    }

    return totalEfficiency / count;
}
