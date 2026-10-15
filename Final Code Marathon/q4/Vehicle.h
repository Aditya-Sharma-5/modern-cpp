#ifndef VEHICLE_H
#define VEHICLE_H

#include<functional>
#include<iostream>
#include"VehicleSensorUnit.h"

using ReferenceWrapper = std::reference_wrapper<VehicleSensorUnit>;

class Vehicle
{
private:

    std::string m_vehicle_id;
    std::string m_vehicle_model_name;
    ReferenceWrapper m_vehicle_sensor_unit;

public:
    Vehicle()  = default;
    ~Vehicle() = default;

    Vehicle(const Vehicle&) = default;
    Vehicle(Vehicle&&) = default;

    Vehicle& operator=(const Vehicle&) = default;
    Vehicle& operator=(Vehicle&&) = default;

    Vehicle(std::string id , std::string name , ReferenceWrapper unit);

    std::string vehicleId() const { return m_vehicle_id; }
    void setVehicleId(const std::string &vehicle_id) { m_vehicle_id = vehicle_id; }

    std::string vehicleModelName() const { return m_vehicle_model_name; }
    void setVehicleModelName(const std::string &vehicle_model_name) { m_vehicle_model_name = vehicle_model_name; }

    ReferenceWrapper vehicleSensorUnit() const { return m_vehicle_sensor_unit; }
    void setVehicleSensorUnit(const ReferenceWrapper &vehicle_sensor_unit) { m_vehicle_sensor_unit = vehicle_sensor_unit; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};


#endif // VEHICLE_H
