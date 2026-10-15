#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Vehicle.h"
#include"EmptyContainerError.h"
#include"IdNotFoundError.h"
#include"UnmatchConditionError.h"
#include<memory>
#include<list>

using Vptr = std::shared_ptr<Vehicle>;

using VehicleContainer = std::list<Vptr>;
using EngineContainer = std::list<Engine>;

using Predicate = std::function<bool(const Vptr&)>;

using UnaryFunction = std::function<float(const Vptr&)>;

/*
    Create at least 4 instances of vehicle class 
    Each vehicle must be associated to one Engine reference_wrapper
    Wrappers need to exists separately from Vehicle
    So there must be 2 containers 1 for vehicle and 1 for Engine

    Input Arguement : Containers
    Expected Output : Filled Containers of Vehicle objects
    Return Tyoe = Void 
*/
void CreateObject(EngineContainer& engine , VehicleContainer& vehicle);


/*
    Input : Const Data container and a predicate function
    Expected Output : We need a containers where pointers of "filtered objects stored "
    Return Type : std::list<Vehicle*> ---[VehicleContainer]
*/
VehicleContainer FilterVehicles(const VehicleContainer& vehicle , Predicate fn);


/*
    Input : Const Data container and a string registration number
    Expected Output : If match is found , its associated Transmission Type must be return 
    Return Type : Transmission Type 
*/
TransmissionType FindTransmissionTypeById(const VehicleContainer& vehicle , std::string id);

/*
    Input : COnst Data container and a UnaryFunction
    Expected :  DIsplay the objects which fulfills the condistion 
    Return Type : Void 
*/
void DisplayTaxAmount(const VehicleContainer& vehicle, UnaryFunction fn);



/*
    Input : Const Data container and a float Threshold
    Expected Output : A container which points to Vehicle with Vehicle Torque Above threshold passed 
    Return Type : std::list<Vehicle*> ---[VehicleContainer]
*/
VehicleContainer AboveThresholdTorqueVehicle(const VehicleContainer& vehicle , float threshold);


/*
     This function is not mandatory , this is used 
     just to check the data.
*/
void showObject(const VehicleContainer& vehicle);


#endif // FUNCTIONALITIES_H


// Dummmy Object

/* 
                   Engine
    [nullptr | 400  | 150.f  | nullptr ]


                                              Vehicle
    [nullptr  | "MH1717"  |  9000.0f  | PERSONAL | 3.1f  | 1.5f  | AMT | PETROL | [///[0X100H]///]] 


*/