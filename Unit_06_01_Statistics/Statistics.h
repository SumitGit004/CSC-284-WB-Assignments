#pragma once

#include <vector>

//Global templated functions for statistical calculations
template <typename T>
T getMin(const std::vector<T>& values){
    if(values.empty()){
        throw std::runtime_error("Input vector is empty");
    }

    T min_value = values[0];

    for (const T &value : values){
        if (value < min_value)
            min_value = value;
    }
    return min_value;
}

template <typename T>
T getMax(const std::vector<T>& values){
    if(values.empty()){
        throw std::runtime_error("Input vector is empty");
    }

    T max_value = values[0];

    for (const T &value : values){
        if (value > max_value)
            max_value = value;
    }
    return max_value;
}

template <typename T>
double getAverage(const std::vector<T>& values){
    if(values.empty()){
        throw std::runtime_error("Input vector is empty");
    }

    double sum = 0;

    for (const T &value : values)
        sum += value;

    return sum / values.size();
}


// class template to store data and provide statistical calculations
template <typename T>
class Statistics {
    private:
    std::vector<T> statsData;

    public:
    void addValue(const T& value){
        statsData.push_back(value);
    }

    T getMin() const{
        if( statsData.empty()){
            throw std::runtime_error ("Statistics is empty");
        }
        
        T min_value =  statsData[0];

        for(const T& value :  statsData) {
            if(value < min_value)
            min_value = value;
        }
        return min_value;
    }

    T getMax() const{
        if( statsData.empty()){
            throw std::runtime_error ("Statistics is empty");
        }
        
        T max_value =  statsData[0];

        for(const T& value :  statsData) {
            if(value > max_value)
            max_value = value;
        }
        return max_value;
    }

    double getAverage() const{
        if( statsData.empty()){
           throw std::runtime_error ("Statistics is empty");
        }

        double sum = 0;

        for(const T&value : statsData) 
            sum += value;
        
        return sum /  statsData.size();
    }
};
