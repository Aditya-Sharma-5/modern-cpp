#ifndef OPERATIONS_H
#define OPERATIONS_H

#include<iostream>
#include<vector>
#include<memory>
#include<mutex>
#include<future>
#include<condition_variable>
#include<optional>
#include "CabRide.h"

using CabContainer =std::vector<std::shared_ptr<CabRide>>;
using DriverContainer=std::vector<Driver>;

class Operations
{
private:
    /* data */
    int _N{0};
    std::mutex mt;
    bool flag=false;
    std::condition_variable cv;
    static std::shared_ptr<Operations> _object;
    CabContainer _cab_data;
    DriverContainer _drivers;
    Operations()=default;

public:
    Operations(const Operations &)=delete;
    Operations(Operations && )=delete;
    Operations & operator=(const Operations & )=delete;
    Operations &operator=(Operations &&)=delete;
    ~Operations()=default;

    static std::shared_ptr<Operations> createInstance();

    void CreateCabObjects();
    PaymentMode PaymentModeByID(std::variant<std::string,int> );
    std::array<RideType,2> MaximumMinimumRideType();

    std::vector<std::string> FirstNPickupLocations(int N);
    void TakeInput();
    void Notify();

    std::vector<Driver> NDriverInstance();
     
};

#endif // OPERATIONS_H
