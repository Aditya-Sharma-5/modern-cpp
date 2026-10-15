#ifndef MOTOR_H
#define MOTOR_H

#include<iostream>
#include"InvalidInputError.h"

class Motor
{
private:
    float _time{0.0f};
    float _maxPower{0.0f};
    int _maxTorque{0};

public:

    Motor() = default;    //Default Constructor
    ~Motor() = default;   //Default Destructor

    Motor(const Motor&) = delete;   //Copy Constructor Disable
    Motor(Motor&&) = delete;        //Move Constructor Disable

    Motor& operator=(const Motor&) = delete;     //Copy Assignment Operator Disable
    Motor& operator=(Motor&&) = delete;          //Copy Assignment Operator Disable


    // Parametrized Constructor
    Motor(float time , float maxPower , int maxTorque);


    // Getters for Data Members 
    float time() const { return _time; }

    float maxPower() const { return _maxPower; }

    int maxTorque() const { return _maxTorque; }


    // Output Stream 
    friend std::ostream &operator<<(std::ostream &os, const Motor &rhs);


    //Overloaded Operator 
    float operator+(const Motor& obj);

};

#endif // MOTOR_H
