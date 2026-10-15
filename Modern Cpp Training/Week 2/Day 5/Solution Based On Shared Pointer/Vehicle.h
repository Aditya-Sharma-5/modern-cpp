#ifndef VEHICLE_H
#define VEHICLE_H
#include<iostream>
#include"VehicleType.h"
#include"TransmissionType.h"
#include"VehicleFuelType.h"
#include"Engine.h"
#include<functional>


using EngineRefWrapper = std::reference_wrapper<Engine>;

class Vehicle
{
private:
    std::string m_vehicle_reg_number;
    float m_vehicle_price;
    VehicleType m_vehicle_type;
    float m_vehicle_chassis_length;
    float m_vehicle_chassis_width;
    TransmissionType m_vehicle_transmission_type;
    VehicleFuelType m_vehicle_fuel_type;
    EngineRefWrapper m_engine_ref;

public:
    Vehicle() = delete;
    ~Vehicle() = default;
    Vehicle(const Vehicle&) = delete;
    Vehicle(Vehicle&&) = delete;
    Vehicle& operator=(const Vehicle&) = delete;
    Vehicle& operator=(Vehicle&&) = delete;

    Vehicle(std::string reg_number , float price , VehicleType vtype , float len , float width , TransmissionType transmission_type , VehicleFuelType ftype , EngineRefWrapper ref);

    std::string vehicleRegNumber() const { return m_vehicle_reg_number; }

    float vehiclePrice() const { return m_vehicle_price; }

    VehicleType vehicleType() const { return m_vehicle_type; }

    float vehicleChassisLength() const { return m_vehicle_chassis_length; }

    float vehicleChassisWidth() const { return m_vehicle_chassis_width; }

    TransmissionType vehicleTransmissionType() const { return m_vehicle_transmission_type; }

    VehicleFuelType vehicleFuelType() const { return m_vehicle_fuel_type; }

    EngineRefWrapper engineRef() const { return m_engine_ref; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};

#endif // VEHICLE_H

/*

    1) Working on reference means
        a) No copies of the original 
        b) Any changes that happens on the references must impact the original data

    2) Reference are just alternate names (aliases) , No physical memory location
        a) No memory means , cannot store it any variable or memory location
        b) to store references ina wrapper , we need to store the address of the data 
            in the wrapper instead


        Input                                Output
    
    T& --------------[   T*     ]--------------T&
*/