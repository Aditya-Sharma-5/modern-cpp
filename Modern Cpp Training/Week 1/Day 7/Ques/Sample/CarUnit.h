#ifndef CARUNIT_H
#define CARUNIT_H

#include"CarType.h"
#include<iostream>

class CarUnit{
    private:
        std::string _id{""};
        std::string _model_name{""};
        float _price{10000.0f};
        CarType _carType{CarType::SEDAN};

    public:

        CarUnit() = default; //Array Initialization in multiple functions
        ~CarUnit() = default;

        CarUnit(const CarUnit&) = delete;
        CarUnit(CarUnit&&) = delete;

        CarUnit& operator=(const CarUnit&) = default;    // [FetchN Instances]
        CarUnit& operator=(CarUnit&&) = default;         // [Create Objects]

        CarUnit(std::string id , std::string model_name , float price , CarType carType);

        std::string id() const { return _id; }

        std::string modelName() const { return _model_name; }

        float price() const { return _price; }

        CarType carType() const { return _carType; }

        friend std::ostream &operator<<(std::ostream &os, const CarUnit &rhs);
};

#endif // CARUNIT_H
