#ifndef ENGINE_H
#define ENGINE_H

#include<iostream>
#include"EngineType.h"

class Engine
{
private:
    std::string _engine_number{""};
    EngineType _engine_type{EngineType::ICT};
    int _engine_horsepower{1000};
    int _engine_torque{1000};
public:
    Engine() = default;
    ~Engine() = default;

    Engine(std::string engine_number , EngineType engine_type , int engine_horsepower , int engine_torque);

    std::string engineNumber() const { return _engine_number; }
    void setEngineNumber(const std::string &engine_number) { _engine_number = engine_number; }

    EngineType engineType() const { return _engine_type; }
    void setEngineType(const EngineType &engine_type) { _engine_type = engine_type; }

    int engineHorsepower() const { return _engine_horsepower; }
    void setEngineHorsepower(int engine_horsepower) { _engine_horsepower = engine_horsepower; }

    int engineTorque() const { return _engine_torque; }
    void setEngineTorque(int engine_torque) { _engine_torque = engine_torque; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
    
};

#endif // ENGINE_H
