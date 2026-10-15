#ifndef ENGINE_H
#define ENGINE_H
#include<iostream>
#include"EngineType.h"


class Engine
{
private:

    //Data Members
    std::string _engineId{""};
    unsigned int _horsepower{0};
    EngineType _engineType{EngineType::PETROL};
    float _engineCapacity{0.0f};
    float _engineTorque{20.0f};
    
public:
    Engine() = default;    //Default Constructor
    ~Engine() = default;   //Default Destructor

    Engine(const Engine&) = delete;   //Copy Constructor Disable
    Engine(Engine&&) = delete;        //Move Constructor Disable

    Engine& operator=(const Engine&) = delete;     //Copy Assignment Operator Disable
    Engine& operator=(Engine&&) = delete;          //Copy Assignment Operator Disable


    // Parametrized Constructor
    Engine(std::string engineId , unsigned int horsepower , EngineType engineType , float engineCapacity , float  engineTorque);

    std::string engineId() const { return _engineId; }
    void setEngineId(const std::string &engineId) { _engineId = engineId; }

    unsigned int horsepower() const { return _horsepower; }
    void setHorsepower(unsigned int horsepower) { _horsepower = horsepower; }

    EngineType engineType() const { return _engineType; }
    void setEngineType(const EngineType &engineType) { _engineType = engineType; }

    float engineCapacity() const { return _engineCapacity; }
    void setEngineCapacity(float engineCapacity) { _engineCapacity = engineCapacity; }

    float engineTorque() const { return _engineTorque; }
    void setEngineTorque(float engineTorque) { _engineTorque = engineTorque; }


    // Output Stream 
    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};

#endif // ENGINE_H
