#ifndef VEHICLE_H
#define VEHICLE_H
#include"Permit.h"
#include"VehicleType.h"
#include<iostream>

class Vehicle
{
private:
    std::string _id{""};
    std::string _name{""};
    VehicleType _vehicle_type{VehicleType::PRIVATE};
    Permit* _permit{nullptr};

public:    
    Vehicle() = delete;
    ~Vehicle() = default;

    Vehicle(const Vehicle&) = delete;
    Vehicle(Vehicle&&) = delete;

    Vehicle& operator=(const Vehicle&) = delete;
    Vehicle& operator=(Vehicle&&) = delete;

    Vehicle(std::string id , std::string name , VehicleType vehicle_type , Permit* permit);

    std::string id() const { return _id; }

    std::string name() const { return _name; }

    VehicleType vehicleType() const { return _vehicle_type; }

    Permit* permit() const { return _permit; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);

};

#endif // VEHICLE_H
