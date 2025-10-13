#pragma once
#include <string>


class Vehicle{
   private:
   std::string make;
   std::string model;
   int year;
   double mileage;
   static int vehicleCount;

   public:

   Vehicle();

   Vehicle(std::string make, std::string model, int year, double mileage);

   virtual ~Vehicle();
    
   std::string getMake() const;

   void setMake(std::string make);

   std::string getModel() const;

   void setModel(std::string model);

   int getYear() const;

   void setYear(int year);

   double getMileage() const;

   void setMileage(double mileage);

   virtual void displayInfo() const;

   virtual double getFuelEfficiency() const = 0;

   static int getVehicleCount();

};