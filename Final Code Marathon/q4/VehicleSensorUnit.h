#ifndef VEHICLESENSORUNIT_H
#define VEHICLESENSORUNIT_H

#include"SensorUnitType.h"
#include<iostream>
#include<array>

class VehicleSensorUnit
{
private:
    SensorUnitType m_sensor_unit_type;
    std::array<float , 5> m_sensor_last_5_reading;
    float m_sensor_threshol_value;

public:
    VehicleSensorUnit()  = default;
    ~VehicleSensorUnit() = default;

    VehicleSensorUnit(const VehicleSensorUnit&) = default;
    VehicleSensorUnit(VehicleSensorUnit&&) = default;

    VehicleSensorUnit& operator=(const VehicleSensorUnit&) = default;
    VehicleSensorUnit& operator=(VehicleSensorUnit&&) = default;

    VehicleSensorUnit(SensorUnitType type , std::array<float,5> last , float value);

    SensorUnitType sensorUnitType() const { return m_sensor_unit_type; }
    void setSensorUnitType(const SensorUnitType &sensor_unit_type) { m_sensor_unit_type = sensor_unit_type; }

    std::array<float , 5> sensorLast5Reading() const { return m_sensor_last_5_reading; }
    void setSensorLast5Reading(const std::array<float , 5> &sensor_last_5_reading) { m_sensor_last_5_reading = sensor_last_5_reading; }

    float sensorThresholValue() const { return m_sensor_threshol_value; }
    void setSensorThresholValue(float sensor_threshol_value) { m_sensor_threshol_value = sensor_threshol_value; }

    friend std::ostream &operator<<(std::ostream &os, const VehicleSensorUnit &rhs);
};

#endif // VEHICLESENSORUNIT_H
