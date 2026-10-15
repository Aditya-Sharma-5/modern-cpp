#ifndef OPERATION_H
#define OPERATION_H

#include"EvCar.h"
#include"Automobile.h"
#include"ExceptionMessage.h"
#include<vector>
#include<iostream>
#include<variant>
#include<array>
#include<mutex>
#include<memory>
#include<thread>

using EvCarPtr = std::shared_ptr<EvCar>;
using AutomobilePtr = std::shared_ptr<Automobile>;

using VarPtr = std::variant<EvCarPtr, AutomobilePtr>;
using Container = std::vector<VarPtr>;

class Operation
{
private:
    // Container data;
    std::array<std::thread, 4> thdata;
    Operation()=default;
    Operation(const Operation&&)=delete;
    Operation(Operation&&)=default;
    Operation& operator=(Operation&&)=delete;
    Operation& operator=(const Operation&)=delete;
    static Operation* object;
    std::mutex mt;
public:
    ~Operation()=default;

    /*
        function to create single instance of Operation
    */
    static Operation* GetInstance();

    /*
        function to create & add instances of EvCar & Automobile in same container
    */
    void CreateObjects(Container& data);

    /*
        function to display average GST of EvCars
    */
    void AverageGSTOfEvCars(Container& data);

    /*
        function to display count of automobile instances with seat count above 4
    */
    void AutomobilesAboveSeatCount4(Container& data);

    /*
        function to dislay average of price of Automobile instances
    */
   void AverageAutomobilePrice(Container& data);

    /*
        function to predicate whether any EvCar instance is of charhing type DC
    */
   void IfAnyDCType(Container& data);

   void MapThread(Operation* ptr,Container& data);

   void JoinThread();
};

#endif // OPERATION_H
