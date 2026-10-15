#ifndef ENGINE_H
#define ENGINE_H

#include "EngineType.h"
#include <iostream>

class Engine
{
private:
    std::string _m_engine_number;
    int _m_enggine_torque;
    int _m_hourse_power;
    EngineType _m_engine_type;

public:
    Engine( std::string m_engine_number,int m_enggine_torque,int m_hourse_power,EngineType m_engine_type);
    Engine() = default;                         // Default constructor
    Engine(const Engine &) = default;           // Copy constructor
    Engine &operator=(const Engine &) = default; // Copy assignment operator
    Engine(Engine &&) = default;                 // Move constructor
    Engine &operator=(Engine &&) = default;      // Move assignment operator
    ~Engine() = default;                        // Destructor

    std::string mEngineNumber() const { return _m_engine_number; }

    int mEnggineTorque() const { return _m_enggine_torque; }

    int mHoursePower() const { return _m_hourse_power; }

    EngineType mEngineType() const { return _m_engine_type; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};

#endif // ENGINE_H
