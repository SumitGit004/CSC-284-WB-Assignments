#include <iostream>
#include "Statistics.h"
using namespace std;

int main() {
    //statistics object instantiated with int type
    Statistics<int> intStatistics;
    intStatistics.addValue(5);
    intStatistics.addValue(18);
    intStatistics.addValue(3);
    intStatistics.addValue(12);
    intStatistics.addValue(7);

    vector<int> intList = {7, 12, 3, 18, 5};

    //statistics object instantiated with double type
    Statistics<double> doubleStatistics;
    doubleStatistics.addValue(3.5);
    doubleStatistics.addValue(1.2);
    doubleStatistics.addValue(10.3);
    doubleStatistics.addValue(6.7);
    doubleStatistics.addValue(9.2);

    vector<double> doubleList = {9.2, 6.7, 10.3, 3.5, 1.2};

    
    cout << "\nDisplaying results for integer statistics\n";

    cout << "\nUsing Statistics class template,\n"
         << "Integer Stats: Min = " << intStatistics.getMin()
         << ", Max = " << intStatistics.getMax()
         << ", Average = " << intStatistics.getAverage() << "\n";

    cout << "\nUsing function template,\n"
         << "Integer Stats: Min = " << getMin(intList)
         << ", Max = " << getMax(intList)
         << ", Average = " << getAverage(intList) << "\n";
     
    cout << "\n----------------------------------------\n"
         << "\nDisplaying results for double statistics\n";

    cout << "\nUsing Statistics class template,\n"
         << "Double Stats: Min = " << doubleStatistics.getMin()
         << ", Max = " << doubleStatistics.getMax()
         << ", Average = " << doubleStatistics.getAverage() << "\n";
    
    cout << "\nUsing function template,\n"
         << "Double Stats: Min = " << getMin(doubleList)
         << ", Max = " << getMax(doubleList)
         << ", Average = " << getAverage(doubleList) << "\n";

    return 0;
}