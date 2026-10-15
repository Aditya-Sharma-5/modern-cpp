#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"ElectricVehicle.h"
#include"EmptyContainerError.h"
#include"InvalidInputError.h"
#include"IdNotFoundError.h"
#include<vector>

using Container = std::vector<ElectricVehicle*>;


/*
    Input Arguement : This function takes an empty Container
    Expected Output : Filled container of objects of ElectricVehicle
    Return Type : Void 
*/
void CreateObject(Container& data);


/*
    Input Arguement : This function takes a filled Container and a string id 
    Expected Output : Max torque if Battery capacity is equal or above 30.3 , else Max Power
    Return Type : Auto [ int/float ]
*/
float MaxTorqueOrMaxPowerOfID(const Container& data , std::string check_id);


/*
    Input Arguement : This function takes a filled Container  
    Expected Output : Displays Battery Discharge Rate of All Instances 
    Return Type     : Void
*/
void DisplayBatteryDrainRate(const Container& data);


/*
    Input Arguement : This function takes a filled Container  
    Expected Output : Float Container having results of +operator of All Instances  of Motor
    Return Type     : Float Container
*/
std::vector<float> ContainerStoringResultOfOperatorOverloading(const Container& data);


/*
    Input Arguement : This function takes a filled Container of Electric Vehicle
    Expected Output : Deallocate heap memory of objects of ElectricVehicle
    Return Type : Void 
*/
void DeallocateMemory(Container& data);


#endif // FUNCTIONALITIES_H
