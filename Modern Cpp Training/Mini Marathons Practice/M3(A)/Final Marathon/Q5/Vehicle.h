#ifndef VEHICLE_H
#define VEHICLE_H

#include"VehicleCategory.h"
#include"TransmissionType.h"
#include<iostream>

class Vehicle
{
private:
    std::string m_vehicle_id;
    float m_vehicle_price;
    VehicleCategory m_vehicle_category;
    TransmissionType m_transmission_type;
    int m_boot_space;
    bool m_is_vehicle_insured;
public:
    Vehicle(/* args */)=delete;
    ~Vehicle()=default;
    Vehicle(Vehicle&&)=delete;
    Vehicle(const Vehicle&)=delete;
    Vehicle& operator=(const Vehicle&)=delete;
    Vehicle& operator=(Vehicle&&)=delete;
    Vehicle(std::string vehicle_id, float vehicle_price, VehicleCategory vehicle_category, TransmissionType transmission_type, int boot_space, bool is_vehicle_insured);

    std::string vehicleId() const { return m_vehicle_id; }

    float vehiclePrice() const { return m_vehicle_price; }

    VehicleCategory vehicleCategory() const { return m_vehicle_category; }

    TransmissionType transmissionType() const { return m_transmission_type; }

    int bootSpace() const { return m_boot_space; }

    bool isVehicleInsured() const { return m_is_vehicle_insured; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};

#endif // VEHICLE_H
