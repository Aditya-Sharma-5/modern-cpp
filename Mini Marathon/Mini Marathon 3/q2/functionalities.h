#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include"Automobile.h"
#include<memory>
#include<list>
#include"EmptyContainerError.h"
#include"UnmatchCondition.h"
#include"InvalidInputError.h"
#include<mutex>


// Containers Aliasis

using Sptr = std::shared_ptr<Automobile>;
using DataContainer = std::list<Sptr>;


// This function is used to create the objects , store them on heap using Shared Pointer
void CreateObject(DataContainer& data);


//  This function is used to fetch the object that satisfies the conditions 
// and return them  in a data container 
DataContainer SatisfiedDataContainer(const DataContainer& data , AutomobileWheelType wheel_type , AutomobileCategory category);


// This function is used to count the automobiles object having range between the given years
int CountOfAutoMobileSatisfiedYear(const DataContainer& data , unsigned int begin , unsigned int end );


// This function is used to check that is All objects satisfiesd at least one condition
bool CheckObjectsBasedOnConditions(const DataContainer& data);


// This function is used to returm the Id of that automobile which have maximum seat count
std::string IdWithMaximumSeatCount(const DataContainer& data);




#endif // FUNCTIONALITIES_H
