#ifndef BIKE_H
#define BIKE_H

#include"VehicleType.h"
#include<iostream>
#include"InvalidInput.h"

class Bike
{
private:
    float bikePrice;
    std::string bikeBrand;
    VehicleType bikeVehicleType;
    float bikeEngineCC;
    int bikeSeatCount;
public:
    Bike() = default;
    ~Bike() = default;

    Bike(const Bike&) = default;
    Bike(Bike&&) = default;

    Bike& operator=(Bike&&) = default;
    Bike& operator=(const Bike&) = default;

    Bike(float price , std::string brand , VehicleType vtype ,  float engine , int seat);

    float getBikePrice() const { return bikePrice; }
    void setBikePrice(float bikePrice_) { bikePrice = bikePrice_; }

    std::string getBikeBrand() const { return bikeBrand; }
    void setBikeBrand(const std::string &bikeBrand_) { bikeBrand = bikeBrand_; }

    VehicleType getBikeVehicleType() const { return bikeVehicleType; }
    void setBikeVehicleType(const VehicleType &bikeVehicleType_) { bikeVehicleType = bikeVehicleType_; }

    float getBikeEngineCC() const { return bikeEngineCC; }
    void setBikeEngineCC(float bikeEngineCC_) { bikeEngineCC = bikeEngineCC_; }

    int getBikeSeatCount() const { return bikeSeatCount; }
    void setBikeSeatCount(int bikeSeatCount_) { bikeSeatCount = bikeSeatCount_; }

    friend std::ostream &operator<<(std::ostream &os, const Bike &rhs);
};

#endif // BIKE_H
