#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Vehicle.h"
#include<vector>
#include<memory>

using StackVehicles = std::vector<Vehicle>;
using RawPointers = std::vector<Vehicle*>;
using Vptr = std::shared_ptr<Vehicle>;
using SmartPointer = std::vector<Vptr>;

void createObjects(StackVehicles& data);

void createObjects(RawPointers& data);

void createObjects(SmartPointer& data);

#endif // FUNCTIONALITIES_H
