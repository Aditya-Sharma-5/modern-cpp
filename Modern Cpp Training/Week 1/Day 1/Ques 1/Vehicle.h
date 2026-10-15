#ifndef VEHICLE_H
#define VEHICLE_H
#include<iostream>
#include "VehicleType.h"
class Vehicle
{
private:
    std::string _vehicle_id{"v111"};
    float _vehicle_price{0.0f};
    VehicleType _vehicle_type{VehicleType::PRIVATE};
    std::string _vehicle_model_name{"Maruti"};

public:
    Vehicle() = default;  //enabled constructor
    ~Vehicle() = default; //enabled destructor

    Vehicle(const Vehicle&) = default;    //enabled copy constructor
    Vehicle& operator=(const Vehicle&) = default;  //enabled copy assignment operator

    Vehicle(Vehicle&&) = delete;    //disabled move constructor
    Vehicle& operator=(Vehicle&&) = delete;  //disabled move assignment operator 

    // Parametrized Constructor 
    Vehicle(std::string vehicle_id , float vehicle_price , VehicleType vehicle_type , std::string vehicle_model_name) ;
    Vehicle(std::string vehicle_id , std::string vehicle_model_name , VehicleType vehicle_type);
};


#endif // VEHICLE_H
