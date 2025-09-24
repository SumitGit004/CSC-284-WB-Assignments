//Simulates the changing traffic light colors for specified number of cycles.
#include <iostream>
#include "TrafficLight.h"
using namespace std;


int main() {
    
    int numberOfCycles;
    TrafficLight trafficLightSimulator;

    
    cout << "Enter number of cycles: ";
    cin >> numberOfCycles;

    trafficLightSimulator.displayLight(numberOfCycles);

    return 0;

}