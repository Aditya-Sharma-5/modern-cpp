#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Car.h"
#include "Engine.h"
#include <vector>
#include <memory>
#include <algorithm>
#include<numeric>
#include "DataEmpty.h"


using CarPtr = std::shared_ptr<Car>;
using Container = std::vector<CarPtr>;
using EngineContainer = std::vector<Engine>;
using RefContainer = std::vector<RefWrapper>;


void CreateObjects(EngineContainer &Edata,Container &data);
std::optional<RefContainer> ReturnTillN(EngineContainer &data,unsigned int N);
bool AllEngineTorqueOver120(const Container &data);
EngineType FindEngineTypeBasedOnID(Container &data,std::string number);
float FindAverageHorsePower(const Container &data);
RefContainer HighestEngineTorque(const Container &data);

void Display(Container &data);

#endif // FUNCTIONALITIES_H
