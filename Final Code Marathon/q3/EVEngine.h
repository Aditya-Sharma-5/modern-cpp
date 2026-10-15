#ifndef EVENGINE_H
#define EVENGINE_H

#include<iostream>
#include"BatteryType.h"

class EVEngine
{
private:
    std::string m_ev_engine_id;
    int m_ev_engine_horsepower;
    float m_ev_engine_torque;
    BatteryType m_engine_battery_pack_type;
    bool m_is_engine_under_warranty;
public:
    EVEngine()  = default;
    ~EVEngine() = default;

    EVEngine(const EVEngine&) = default;
    EVEngine(EVEngine&&) = default;

    EVEngine& operator=(const EVEngine&) = default;
    EVEngine& operator=(EVEngine&&) = default;

    EVEngine(std::string id , int hp , float tq , BatteryType type , bool warranty);

    std::string evEngineId() const { return m_ev_engine_id; }
    void setEvEngineId(const std::string &ev_engine_id) { m_ev_engine_id = ev_engine_id; }

    int evEngineHorsepower() const { return m_ev_engine_horsepower; }
    void setEvEngineHorsepower(int ev_engine_horsepower) { m_ev_engine_horsepower = ev_engine_horsepower; }

    float evEngineTorque() const { return m_ev_engine_torque; }
    void setEvEngineTorque(float ev_engine_torque) { m_ev_engine_torque = ev_engine_torque; }

    BatteryType engineBatteryPackType() const { return m_engine_battery_pack_type; }
    void setEngineBatteryPackType(const BatteryType &engine_battery_pack_type) { m_engine_battery_pack_type = engine_battery_pack_type; }

    bool isEngineUnderWarranty() const { return m_is_engine_under_warranty; }
    void setIsEngineUnderWarranty(bool is_engine_under_warranty) { m_is_engine_under_warranty = is_engine_under_warranty; }

    friend std::ostream &operator<<(std::ostream &os, const EVEngine &rhs);

    float AnnualMaintainanceCost();
};

#endif // EVENGINE_H
