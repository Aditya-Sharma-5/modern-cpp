#include "EVCar.h"

EVCar::EVCar(std::string m_car_id, int m_battery_charging_time, PlatformType m_platform, float m_chasis_length, int m_seat_count, int m_top_speed) : _m_car_id{m_car_id}, _m_battery_charging_time{m_battery_charging_time}, _m_platform{m_platform}, _m_chasis_length{m_chasis_length}, _m_seat_count{m_seat_count}, _m_top_speed{m_top_speed}
{
}

std::ostream &operator<<(std::ostream &os, const EVCar &rhs)
{
    os << "_m_car_id: " << rhs._m_car_id
       << " _m_battery_charging_time: " << rhs._m_battery_charging_time;
    if (rhs._m_platform == PlatformType::IC_BASED)
    {
        os << "Platform : IC-BASED";
    }
    else
    {
        os << "Platform : PURE-EV";
    }
    os << " _m_chasis_length: " << rhs._m_chasis_length
       << " _m_seat_count: " << rhs._m_seat_count
       << " _m_top_speed: " << rhs._m_top_speed;
    return os;
}
