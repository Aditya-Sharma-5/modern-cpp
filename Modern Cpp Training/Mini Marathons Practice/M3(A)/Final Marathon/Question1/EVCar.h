#ifndef EVCAR_H
#define EVCAR_H

#include <iostream>
#include "PlatformType.h"
class EVCar
{
private:
    std::string _m_car_id;
    int _m_battery_charging_time;
    PlatformType _m_platform;
    float _m_chasis_length;
    int _m_seat_count;
    int _m_top_speed;

public:
    EVCar() = default; // Default constructor
    EVCar(std::string m_car_id, int m_battery_charging_time, PlatformType m_platform, float m_chasis_length, int m_seat_count, int m_top_speed);
    EVCar(const EVCar &) = default;           // Copy constructor
    EVCar &operator=(const EVCar &) = delete; // Copy assignment operator
    EVCar(EVCar &&) = delete;                 // Move constructor
    EVCar &operator=(EVCar &&) = delete;      // Move assignment operator
    ~EVCar() = default;                       // Destructor

    std::string mCarId() const { return _m_car_id; }

    int mBatteryChargingTime() const { return _m_battery_charging_time; }

    PlatformType mPlatform() const { return _m_platform; }

    float mChasisLength() const { return _m_chasis_length; }

    int mSeatCount() const { return _m_seat_count; }

    int mTopSpeed() const { return _m_top_speed; }

    friend std::ostream &operator<<(std::ostream &os, const EVCar &rhs);
};

#endif // EVCAR_H
