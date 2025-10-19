#include <print>
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"
#include "Fleet.h"
using namespace std;

int main() {
    Fleet fleet;
    
    fleet.addVehicle(new Car("Toyota", "Rav4", 2022, 15000, 4, false));
    std::print("\n2020 Toyota Rav4 has been added to the fleet.\n");

    fleet.addVehicle(new Truck("Ford", "F-150", 2018, 90000, 18));
    std::print("\n2018 Ford F-150 has been added to the fleet.\n");

    fleet.addVehicle(new Motorcycle("Honda", "XR650L", 2020, 50000, false));
    std::print("\n2020 Honda XR650 has been added to the fleet.\n");

    fleet.addVehicle(new Car("BYD", "Han Ev", 2023, 5000, 4, true));
    std::print("\n2023 BYD Han Ev has been added to the fleet.\n");

    fleet.addVehicle(new Car("Honda", "Civic", 2010, 87000, 2, false));
    std::print("\n2010 Honda Civic has been added to the fleet.\n");

    std::print("\n--Fleet Vehicles--\n\n");

    fleet.displayAllVehicles();

    std::println("\nTotal Vehicles: {}", Vehicle::getVehicleCount());
    std::println("Average Fuel Efficiency: {}km/l\n", fleet.getAverageEfficiency());

    std::println("\nProgram ends...Destructors are called automatically in the order of:\n");
    std::println("derived destructor -> derived's  data members destructor -> base destructor\n\n");

    return 0;
}
