#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include"VehicleType.h"

class Vehicle
{
private:
    std::string m_vehicle_id ;
    std::string m_vehicle_model_name ;
    VehicleType m_vehicle_type;
    float m_vehicle_price ; 
    int m_vehicle_manufacturing_year ; 
    bool m_is_vehicle_ncap_certified;
    bool m_is_vehicle_previously_owned;

public:
    Vehicle() = default;
    ~Vehicle()  = default;

    Vehicle(const Vehicle&) = default;
    Vehicle(Vehicle&&) = default;

    Vehicle& operator=(const Vehicle&) = default;
    Vehicle& operator=(Vehicle&&) = default;

    Vehicle(std::string id , std::string name , VehicleType type , float price , int year , bool ncap , bool owned);

    std::string vehicleId() const { return m_vehicle_id; }
    void setVehicleId(const std::string &vehicle_id) { m_vehicle_id = vehicle_id; }

    std::string vehicleModelName() const { return m_vehicle_model_name; }
    void setVehicleModelName(const std::string &vehicle_model_name) { m_vehicle_model_name = vehicle_model_name; }

    VehicleType vehicleType() const { return m_vehicle_type; }
    void setVehicleType(const VehicleType &vehicle_type) { m_vehicle_type = vehicle_type; }

    float vehiclePrice() const { return m_vehicle_price; }
    void setVehiclePrice(float vehicle_price) { m_vehicle_price = vehicle_price; }

    int vehicleManufacturingYear() const { return m_vehicle_manufacturing_year; }
    void setVehicleManufacturingYear(int vehicle_manufacturing_year) { m_vehicle_manufacturing_year = vehicle_manufacturing_year; }

    bool isVehicleNcapCertified() const { return m_is_vehicle_ncap_certified; }
    void setIsVehicleNcapCertified(bool is_vehicle_ncap_certified) { m_is_vehicle_ncap_certified = is_vehicle_ncap_certified; }

    bool isVehiclePreviouslyOwned() const { return m_is_vehicle_previously_owned; }
    void setIsVehiclePreviouslyOwned(bool is_vehicle_previously_owned) { m_is_vehicle_previously_owned = is_vehicle_previously_owned; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);

    float InsurancePremiumCost();

    float CalculateGSTAmount();
};

#endif // VEHICLE_H
