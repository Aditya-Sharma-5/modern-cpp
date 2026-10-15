#ifndef ICENGINE_H
#define ICENGINE_H

#include<iostream>
#include"EngineType.h"


class ICEngine
{
private:
    std::string m_ic_engine_id;
    int m_ic_engine_horsepower;
    float m_ic_engine_torque;
    EngineType m_engine_type;
    bool m_is_engine_under_warranty;
public:
    ICEngine()  = default;
    ~ICEngine() = default;

    ICEngine(const ICEngine&) = default;
    ICEngine(ICEngine&&) = default;

    ICEngine& operator=(const ICEngine&) = default;
    ICEngine& operator=(ICEngine&&) = default;

    ICEngine(std::string id , int hp , float tq , EngineType type , bool warranty);

    std::string icEngineId() const { return m_ic_engine_id; }
    void setIcEngineId(const std::string &ic_engine_id) { m_ic_engine_id = ic_engine_id; }

    int icEngineHorsepower() const { return m_ic_engine_horsepower; }
    void setIcEngineHorsepower(int ic_engine_horsepower) { m_ic_engine_horsepower = ic_engine_horsepower; }

    float icEngineTorque() const { return m_ic_engine_torque; }
    void setIcEngineTorque(float ic_engine_torque) { m_ic_engine_torque = ic_engine_torque; }

    EngineType engineType() const { return m_engine_type; }
    void setEngineType(const EngineType &engine_type) { m_engine_type = engine_type; }

    bool isEngineUnderWarranty() const { return m_is_engine_under_warranty; }
    void setIsEngineUnderWarranty(bool is_engine_under_warranty) { m_is_engine_under_warranty = is_engine_under_warranty; }

    friend std::ostream &operator<<(std::ostream &os, const ICEngine &rhs);

    float AnnualEngineMaintenanceCost();
};


#endif // ICENGINE_H
