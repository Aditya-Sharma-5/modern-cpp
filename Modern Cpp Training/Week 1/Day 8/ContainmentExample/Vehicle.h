#ifndef VEHICLE_H
#define VEHICLE_H
#include"VehicleType.h"
#include"VehicleRegistrationPermit.h"
#include<iostream>

class Vehicle
{
private:
    std::string _id;
    std::string _name;
    VehicleType _vehicle_type;
    VehicleRegistrationPermit* _permit ;


public:
    Vehicle() = delete ; 
    ~Vehicle(){
        delete _permit;
    } 

    Vehicle(const Vehicle&) = delete;
    Vehicle(Vehicle&&) = delete;

    Vehicle& operator=(const Vehicle&) = delete;
    Vehicle& operator=(Vehicle&&) = delete;

    Vehicle(std::string id , std::string name , VehicleType vehicle_type , VehicleRegistrationPermit* permit);

    std::string id() const { return _id; }

    std::string name() const { return _name; }

    VehicleType vehicleType() const { return _vehicle_type; }

    VehicleRegistrationPermit* permit() const { return _permit; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};



#endif // VEHICLE_H
