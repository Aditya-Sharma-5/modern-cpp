#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Vehicle.h"
#include<vector>
#include<algorithm>
#include<numeric>
#include<thread>
#include<mutex>

using Container = std::vector<Vehicle>;
using ThreadContainer = std::vector<std::thread>;


// This function is used to create the objects on the stack memory 
void CreateObject(Container& data);

// This function display the average Insurance Premium Cost for the first N instances 
void DisplayAverageInsurancePremiumCost(const Container& data , unsigned int N);

// This function prints true or false for the given constion satisfaction
void IsAllObjectsHaveNCAPCertified(const Container& data);

// This finction prints the VehicleType for the given id
void FindVehicleTypeForGivenID(const Container& data , std::string id);

//This function prints the count of the vehicle thatsatisfied the consitions
void DisplayCount(const Container& data );

void JoinThread(ThreadContainer& data);

void CreateThread(ThreadContainer& data , const Container& data1);

#endif // FUNCTIONALITIES_H
