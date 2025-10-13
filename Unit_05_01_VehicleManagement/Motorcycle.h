#pragma once
#include "Vehicle.h"

class Motorcycle : public Vehicle{
   private:
   bool hasSideCar;

   public:
   Motorcycle();

   Motorcycle(std::string make, std::string model, int year, double mileage,bool hasSideCar);

   ~Motorcycle();

   bool isThereSideCar() const;

   double getFuelEfficiency() const override;

   void displayInfo() const override;
   
};