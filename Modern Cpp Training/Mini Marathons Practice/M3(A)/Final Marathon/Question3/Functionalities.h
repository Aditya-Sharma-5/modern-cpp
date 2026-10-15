#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "DataEmpty.h"
#include "InvalidIndex.h"
#include "CarUnit.h"
#include <memory>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <vector>

using CarPtr = std::shared_ptr<CarUnit>;
using Container = std::unordered_map<std::string,CarPtr>;
using MapEntry = std::pair<std::string,CarPtr>;
using ContainerV = std::vector<CarPtr>;

void CreateData(Container &data);
bool CheckAllGearBox(Container &data);
std::optional< Container > ReturnAllMatchingInstance(Container &data, CarType c);
int ReturnCarPrice(Container &data);
int CountofInstancesOverThreshold(Container &data,unsigned int n);
int FindTopRPMbasedOntheId(Container &data,std::string m);

#endif // FUNCTIONALITIES_H
