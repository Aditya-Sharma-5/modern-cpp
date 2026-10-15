#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <thread>
#include "Car.h"
#include "Engine.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>
#include "DataEmpty.h"

#include <iostream>
class DataHandler;
using UniquePointer = std::unique_ptr<DataHandler>;
using CarPtr = std::shared_ptr<Car>;
using Container = std::vector<CarPtr>;
using EngineContainer = std::vector<Engine>;
using RefContainer = std::vector<RefWrapper>;
class DataHandler
{
private:
    DataHandler() = default;                              // Default constructor
    DataHandler(const DataHandler &) = default;           // Copy constructor
    DataHandler &operator=(const DataHandler &) = delete; // Copy assignment operator
    DataHandler(DataHandler &&) = delete;                 // Move constructor
    DataHandler &operator=(DataHandler &&) = delete;      // Move assignment operator
    static UniquePointer _only_object;

public:
    static UniquePointer &_getinstance();
    ~DataHandler() = default; // Destructor
    void CreateObjects(EngineContainer &Edata, Container &data);
    std::optional<RefContainer> ReturnTillN(EngineContainer &data, unsigned int N);
    bool AllEngineTorqueOver120(const Container &data);
    EngineType FindEngineTypeBasedOnID(Container &data, std::string number);
    float FindAverageHorsePower(const Container &data);
    RefContainer HighestEngineTorque(const Container &data);
};

#endif // DATAHANDLER_H
