#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Vehicle.h"
#include<vector>
#include<future>
#include<thread>
#include<mutex>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<memory>
#include"EmptyContainerError.h"
#include"UnmatchConditionError.h"
#include"InvalidInputError.h"

using Vptr = std::shared_ptr<Vehicle>;
using MiniContainer = std::vector<VehicleSensorUnit>;
using DataContainer = std::vector<Vptr>;
using Set = std::unordered_set<SensorUnitType>;
using Predicate = std::function<bool(Vptr)>;


//This function creates the objects of VehicleSensor Unit on stack and Vehicle objects on heap
// with the hepl of smart pointers
void CreateObject(DataContainer& data , MiniContainer& mini);


//This function returns the Container of SensorUnitType 
Set ContainerOfSesonUnitType(const DataContainer& data);


//This function returns the last N instances of VehicleSensorUnit Class
MiniContainer LastNSensorUnits(const DataContainer& data ,unsigned int N);


//This function returns the maximum value from the Last 5 readings 
float MaximumSensorReading(const DataContainer& data , std::string id);


//This function is used to return the count of Vehicle Instances based on Predicate function
int CountOfVehicleInstance(const DataContainer& data , Predicate fn);

#endif // FUNCTIONALITIES_H
