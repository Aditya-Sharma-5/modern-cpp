#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include"Engine.h"
#include"EmptyContainerError.h"
#include"UnmatchConditionError.h"
#include"IndexOutOfBound.h"
#include<vector>

using DataContainer = std::vector<Engine*>;


/*
    Input Arguement : This function takes an empty Container
    Expected Output : Filled container of objects
    Return Type : Void 
*/
void CreateObject(DataContainer& data);


/*
    Input Arguement : This function takes a filled Container of Objects
    Expected Output : Container having EngineType matching the given criteria
    Return Type : Container of EngineType 
*/
std::vector<EngineType> ContainerOfEngineType(const DataContainer& data);

/*
    Input Arguement : This function takes a filled Container of Objects
    Expected Output : True if at least one instance have engineTorque below 110, else False
    Return Type : Bool 
*/
bool AtLeastOneInstanceHaveTorqueBelow110(const DataContainer& data);

/*
    Input Arguement : This function takes a filled Container and a index position
    Expected Output : Show the Details of the instance at that index position.
    Return Type : Void 
*/
void ShowInstanceDetails(const DataContainer& data , int index);

/*
    Input Arguement : This function takes a filled Container and a float value for comparision
    Expected Output : Count of the instances having higher engineCapacity than given 
    Return Type : Int
*/
int InstancesHavingHigherEngineCapacity(const DataContainer& data , float capacity);

/*
    Input Arguement : This function takes a filled Container
    Expected Output : Deallocate the memory on heap
    Return Type : Void 
*/
void DeallocateMemory(DataContainer& data);



#endif // FUNCTIONALITY_H
