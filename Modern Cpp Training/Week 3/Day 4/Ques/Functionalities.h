#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Vehicle.h"
#include<memory>
#include<vector>
#include<mutex>


using Vptr = std::shared_ptr<Vehicle>;
using DataContainer = std::vector<Vptr>;

void CreateObject(DataContainer& data);

void DisplayChassisTypeForGivenIds(const DataContainer& data , std::list<std::string> ids);

void MaxPriceOfFirstNInstances(const DataContainer& data , unsigned int N);

void CountVehicleOfGivenCategory(const DataContainer& data , VehicleCategory category);

void DisplayFirstNVehicle(const DataContainer& data , unsigned int N);

void AreAllCarPricesAboveGivenThreshold(const DataContainer& data , float threshold);

#endif // FUNCTIONALITIES_H
