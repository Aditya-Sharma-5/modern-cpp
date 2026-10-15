#ifndef ELECTRICVEHICLE_H
#define ELECTRICVEHICLE_H

#include"BatteryType.h"
#include"Motor.h"

class ElectricVehicle
{
private:
    std::string _id{""};
    std::string _model{""};
    BatteryType _battery_type{BatteryType::LITHIUM_ION};
    float _batteryCapacity{0.0f};
    Motor* _motor{nullptr};
public:

    ElectricVehicle() = default;    //Default Constructor
    ~ElectricVehicle() = default;   //Default Destructor

    ElectricVehicle(const ElectricVehicle&) = delete;   //Copy Constructor Disable
    ElectricVehicle(ElectricVehicle&&) = delete;        //Move Constructor Disable

    ElectricVehicle& operator=(const ElectricVehicle&) = delete;     //Copy Assignment Operator Disable
    ElectricVehicle& operator=(ElectricVehicle&&) = delete;          //Copy Assignment Operator Disable


    // Parametrized Constructor
    ElectricVehicle(std::string id , std::string model , BatteryType battery_type , float batteryCapacity , Motor* motor);


    // Getter and Setter for Data Members
    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    std::string model() const { return _model; }
    void setModel(const std::string &model) { _model = model; }

    BatteryType batteryType() const { return _battery_type; }
    void setBatteryType(const BatteryType &battery_type) { _battery_type = battery_type; }

    Motor* motor() const { return _motor; }
    void setMotor(Motor* motor) { _motor = motor; }

    float batteryCapacity() const { return _batteryCapacity; }
    void setBatteryCapacity(float batteryCapacity) { _batteryCapacity = batteryCapacity; }


    // Member Function
    float EvaluateChargingRate();


    // Overloaded Operator
    float operator+(const ElectricVehicle& obj);

    friend std::ostream &operator<<(std::ostream &os, const ElectricVehicle &rhs);

};

#endif // ELECTRICVEHICLE_H
