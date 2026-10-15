#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "DataEmpty.h"
#include <functional>
#include "InvalidIndex.h"
#include "EVCar.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>
#include <list>

using EvPtr = std::shared_ptr<EVCar>;
using Container = std::vector<EvPtr>;



void CreateObjects(Container &data);
void Display(Container &data,int n);

std::optional<std::list<EvPtr>> ReturnTillN(const Container &data,unsigned int N);

int CountofInstances(Container &data);

int FindTopSpeed(const Container &data,std::string id);

bool FindPureEv(const Container &data);

void Adaptor(Container &data,int N,std::function<void(Container &,int )> fn);

#endif // FUNCTIONALITIES_H
