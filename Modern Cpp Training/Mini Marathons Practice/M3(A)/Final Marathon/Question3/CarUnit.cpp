#include "CarUnit.h"

CarUnit::CarUnit(std::string m_car_brand, float m_car_price, CarType m_car_type, int m_car_top_speed, int m_car_top_rpm, GearSystemType m_car_gear_system) : _m_car_brand{m_car_brand}, _m_car_price{m_car_price}, _m_car_type{m_car_type}, _m_car_top_speed{m_car_top_speed}, _m_car_top_rpm{m_car_top_rpm}, _m_car_gear_system{m_car_gear_system}
{
}
std::ostream &operator<<(std::ostream &os, const CarUnit &rhs)
{
    os << "_m_car_brand: " << rhs._m_car_brand
       << " _m_car_price: " << rhs._m_car_price;
    if (rhs._m_car_type == CarType::HATCHBACK)
    {
        os << " Car Type is - HatchBack";
    }
    else if (rhs._m_car_type == CarType::SUV)
    {
        os << " Car Type is - SUV";
    }
    else
    {
        os << " Car Type is - SEDAN";
    }
    os << " _m_car_top_speed: " << rhs._m_car_top_speed
       << " _m_car_top_rpm: " << rhs._m_car_top_rpm;

    if (rhs._m_car_gear_system == GearSystemType::CLASSIC)
    {
        os << "Gear System - Classic";
    }
    else if (rhs._m_car_gear_system == GearSystemType::PRNDL)
    {
        os << "Gear System - PRNDL";
    }
    if (rhs._m_car_gear_system == GearSystemType::TIPTRONIC)
    {
        os << "Gear System - TIPTRONIC";
    }
    return os;
}
