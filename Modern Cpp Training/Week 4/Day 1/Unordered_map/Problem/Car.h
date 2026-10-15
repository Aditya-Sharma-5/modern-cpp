#ifndef CAR_H
#define CAR_H

#include<iostream>
#include"CarType.h"
class Car
{
private:
    std::string registration_number;
    float m_price;
    CarType m_type;

    
public:

    Car() = delete;
    ~Car()  = default;

    Car(const Car&) = default;
    Car(Car&&) = default;
    
    Car& operator&(const Car&) = delete;
    Car& operator&(Car&&) = delete;

    Car(std::string reg , float price , CarType type);

    std::string registrationNumber() const { return registration_number; }
    void setRegistrationNumber(const std::string &registrationNumber) { registration_number = registrationNumber; }

    float price() const { return m_price; }
    void setPrice(float price) { m_price = price; }

    CarType type() const { return m_type; }
    void setType(const CarType &type) { m_type = type; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);


};

#endif // CAR_H
