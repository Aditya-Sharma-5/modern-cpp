#ifndef FUNCTIONAITIES_H
#define FUNCTIONAITIES_H

#include"Cab.h"
#include<unordered_map>
#include<memory>
#include<vector>
#include"EmptyContainerError.h"
#include"UnmatchConditionError.h"
#include"InvalidInput.h"
#include<algorithm>
#include<numeric>

using Cptr = std::shared_ptr<Cab>;
using DataContainer = std::unordered_map<std::string , Cptr>;

void CreateObject(DataContainer& data);

std::vector<CabFuelType> ContainerOfFUELType(const DataContainer& data , unsigned int N);

int CountOfMatchCABSTATUS(const DataContainer& data , CabStatus status);

bool Atleast1CabHaveSeatAbove5(const DataContainer& data);

std::vector<CabType> ContainerOfCABTYPE(const DataContainer& data , unsigned int N);

int AverageSeatCount(const DataContainer& data);

std::pair<bool , CabFuelType> PairForGivenId(const DataContainer& data , std::string id);


#endif // FUNCTIONAITIES_H
