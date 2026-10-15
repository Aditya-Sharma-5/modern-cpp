#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"CarUnit.h"
#include<array>
#include"InvalidError.h"
#include"IdNotFoundError.h"

using DataContainer = std::array<CarUnit , 4>;


/*
    Input Arguements : An empty array of 4 car objects
    Expected Output  : Data gets populated or filled in the array 
    Return Type      : void [as not returning anything ]
*/
void createObject(DataContainer& data);


/*
    INput Arguements : A constant  array  of 4 objects , N (no. of instances to be fetched  )
    Expected output : A container of N objects will be created
    return type : a pointer of type CarUnit ( with base address to N instances of car)

*/
CarUnit* FetchNInstances(const DataContainer& data , unsigned int N);


/* 
    INput Arguements : A const array of 4 car objects , Id
    Expected Output  : Matching Cartype 
    Return Type      : CarType
*/
CarType FindCarTypeById(const DataContainer& data , const std::string& id);


/*
    Input Arguements : a const array of 4 objects
    Expected Output  : Average Price 
    Return Type : float
*/
float AveragePrice(const DataContainer& data);

/*
    Input Arguements : A const array of 4 objects
    Expected output  : model name for max price car
    Return type      : std::string 
*/

std::string MaxCarModelName(const DataContainer& data);

#endif // FUNCTIONALITIES_H
