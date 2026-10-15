#ifndef CAR_H
#define CAR_H

#include<iostream>
#include"CarType.h"
#include"Engine.h"
class Car
{
private:
    std::string _car_id{""};
    std::string _car_brand{""};
    CarType _car_type{CarType::HATCHBACK};
    Engine* _car_engine{nullptr};
    float _car_price{0.0f};  

public: 
    Car()= default;
    ~Car() = default;

    Car(std::string car_id , std::string car_brand , CarType car_type, Engine* car_engine , float car_price);

    std::string carId() const { return _car_id; }
    void setCarId(const std::string &car_id) { _car_id = car_id; }

    std::string carBrand() const { return _car_brand; }
    void setCarBrand(const std::string &car_brand) { _car_brand = car_brand; }

    CarType carType() const { return _car_type; }
    void setCarType(const CarType &car_type) { _car_type = car_type; }

    float carPrice() const { return _car_price; }
    void setCarPrice(float car_price) { _car_price = car_price; }

    Engine* carEngine() const { return _car_engine; }
    void setCarEngine(Engine* car_engine) { _car_engine = car_engine; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

};

#endif // 
