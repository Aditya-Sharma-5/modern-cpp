#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Project.h"
// #include<vector>
#include<list>
#include<memory>
#include<functional>
#include<algorithm>
#include"EmptyContainerError.h"
#include"InvalidInput.h"
#include"NoConditionFound.h"
#include<numeric>

using Sptr = std::shared_ptr<Project>;
using DataContainer = std::list<Sptr>;
using Predicate = std::function<bool(const Sptr&)>;
using TDSAmountContainer = std::list<float>;

void CreatObject(DataContainer& data);

std::size_t CountMatchingTypes(const DataContainer& data , ProjectType type);

float FindProjectBudgetById(const DataContainer& data , std::string id);

void CheckCondition(const DataContainer& data);

DataContainer ReturnMatchingInstance(const DataContainer& data , Predicate fn);

DataContainer ReturnFIrstNInstance(const DataContainer& data , unsigned int N);

DataContainer ReturnLastNInstance(const DataContainer& data , unsigned int N);

float FIndAverageProjectBudget(const DataContainer& data);

float FindTotalExpectedRevenueForGivenRange(const DataContainer& data , unsigned int start_idx , unsigned int end_idx);

TDSAmountContainer FIndTDSAmounts(const DataContainer& data);

#endif // FUNCTIONALITIES_H
