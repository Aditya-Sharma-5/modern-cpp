#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include"VehicleType.h"

class Vehicle
{
private:
    int m_id;
    std::string m_name ;
    float m_price;
    unsigned int m_seat_count;
    VehicleType m_vehicle_type;

public:
    Vehicle() = delete;
    ~Vehicle() = default;

    Vehicle(const Vehicle&) = default;
    Vehicle(Vehicle&&) = default;

    Vehicle& operator=(const Vehicle&) = default;
    Vehicle& operator=(Vehicle&&) = default;

    Vehicle(int id , std::string name , float price , unsigned int s_cnt , VehicleType vtype);

    int id() const { return m_id; }
    void setId(int id) { m_id = id; }

    std::string name() const { return m_name; }
    void setName(const std::string &name) { m_name = name; }

    float price() const { return m_price; }
    void setPrice(float price) { m_price = price; }

    unsigned int seatCount() const { return m_seat_count; }
    void setSeatCount(unsigned int seat_count) { m_seat_count = seat_count; }

    VehicleType vehicleType() const { return m_vehicle_type; }
    void setVehicleType(const VehicleType &vehicle_type) { m_vehicle_type = vehicle_type; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};

std::ostream& operator<<(std::ostream & os , const VehicleType& rhs);

#endif // VEHICLE_H
