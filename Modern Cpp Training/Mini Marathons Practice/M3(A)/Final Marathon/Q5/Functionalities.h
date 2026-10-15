#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Vehicle.h"
#include"ExceptionMessage.h"
#include<list>
#include<memory>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<vector>
#include<functional>

using VehiclePtr = std::shared_ptr<Vehicle>;
using Container = std::vector<VehiclePtr>;

/*
    function create objects of Vehicle store it in a list container
*/
void CreateObjects(Container& data);

/*
    function returns container of Transmission Type of last N instances where N is given by user
*/
std::vector<TransmissionType> LastNInstancesTransmissionType(const Container& data, int N);

/*
    function returns priority queue that satisfies given functions condition
*/
std::priority_queue<VehiclePtr,Container,std::function<bool(const VehiclePtr&,const VehiclePtr&)>> PriorityQueueForGivenFunction(const Container& data,std::function<bool(const VehiclePtr&,const VehiclePtr&)>fn);

/*
    function returns unordered set of vehicle price
*/
std::unordered_set<float> VehiclePriceSet(const Container& data);

/*
    functions returns unordered map with id as key & category as value of N instances, N is given
    by user
*/
std::unordered_map<std::string,VehicleCategory> MapOfIdAndCategory(const Container& data, int N);

/*
    function accepts list of id & return container of boot_space of given ids
*/
std::vector<int> BootSpaceOfGivenIds(const Container& data, std::list<std::string> ids);

/*
    function accepts a unary function as input & apply that operation on boot space of all instances
    & returns container of values after performing operation
*/
std::vector<int> BootSpaceOperationContainer(const Container& data, std::function<int(int)>fn);

/*
    function returns container of instances of insured vehicles
*/
Container InsuredVehicles(const Container& data);

#endif // FUNCTIONALITIES_H
