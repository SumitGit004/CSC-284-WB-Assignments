#pragma once//includes this header files only once

#include <vector>
#include <string>
#include <print>

//TrafficLight class simulates the changing changing traffic light colors
class TrafficLight{
private:
   std::vector<std::string> trafficLightColors = {"Red", "Green", "Yellow"};

public:
//displayLight function displays the traffic light colors for specified number of cycles
   void displayLight(int numberOfCycles) {

      for (int i = 0; i < numberOfCycles; i++) {

         std::println("{}", trafficLightColors[i % 3]);
      }
   }
};