#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include<list>
#include"VehicleCategory.h"
#include"ChassisType.h"
#include"Feature.h"

using FeatureList = std::list<Feature>;

class Vehicle
{
private:
    std::string m_id{};
    float m_price{};
    ChassisType m_chassis_type{};
    VehicleCategory m_vehicle_category{};
    float m_chassis_length{};
    FeatureList m_feature{};
public:
    Vehicle() = default;
    ~Vehicle() = default;

    Vehicle(const Vehicle&) = delete;
    Vehicle(Vehicle&&) = delete;

    Vehicle& operator=(const Vehicle&) = delete;
    Vehicle& operator=(Vehicle&&) = delete;

    Vehicle(std::string id , float price , ChassisType ctype , VehicleCategory vCategory , float len , FeatureList feature);

    std::string id() const { return m_id; }
    void setId(const std::string &id) { m_id = id; }

    float price() const { return m_price; }
    void setPrice(float price) { m_price = price; }

    ChassisType chassisType() const { return m_chassis_type; }
    void setChassisType(const ChassisType &chassis_type) { m_chassis_type = chassis_type; }

    VehicleCategory vehicleCategory() const { return m_vehicle_category; }
    void setVehicleCategory(const VehicleCategory &vehicle_category) { m_vehicle_category = vehicle_category; }

    float chassisLength() const { return m_chassis_length; }
    void setChassisLength(float chassis_length) { m_chassis_length = chassis_length; }

    FeatureList feature() const { return m_feature; }
    void setFeature(const FeatureList &feature) { m_feature = feature; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);

};

#endif // VEHICLE_H
