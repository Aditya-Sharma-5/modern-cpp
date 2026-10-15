#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Vehicle.h"
#include<vector>
#include"EmptyContainer.h"

using Container = std::vector<Vehicle*>;

void createObject(Container& data);

void showObject(const Container& data);

int countObjectByVehicleType(const Container& data , VehicleType type);

bool IsSamePermitYear(const Container& data);

Container LastNInstances(const Container& data , int N);

void deleteObject(Container& data);

#endif // FUNCTIONALITIES_H
