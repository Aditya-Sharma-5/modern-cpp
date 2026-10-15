#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Car.h"
#include"Bike.h"
#include"EmptyContainerError.h"
#include"InvalidInput.h"
#include<mutex>
#include<memory>
#include<thread>
#include<optional>
#include<variant>
#include<vector>


using BikePtr = std::shared_ptr<Bike>;
using CarPtr = std::shared_ptr<Car>;

using Vr = std::variant<CarPtr , BikePtr>;
using VrContainer = std::vector<Vr>;


// This function is used to create the objects of Car & Bike 
void CreateObject(VrContainer& data);


// This function either returns the Average of the RTO Charges for all Cars present 
// in the container or nullOpt
std::optional<float> AverageRTOChagesOFALLCars(const VrContainer& data);


// This function either returns the container having Vehicle Types of all Bikes & Cars 
// below threshold price or std::nullopt
std::optional<std::vector<VehicleType>> AllVehiclesTypesOfBelowThresholdPrice(const VrContainer& data , float price);

// This function return either true/false based on the condition or std::nullopt
bool IsAllVariantsOfSameType(const VrContainer& data);


// This function returns all the Bike Objects having EngineCC above the
// given threshold value 
std::optional<std::vector<BikePtr>> BikeInstancesHavingEngineCCAboveThreshold(const VrContainer& data , float cc);

// template<typename T , typename s>
// void Display(T data , std::string brand)
// {
//     if(data.empty())
//     {
//         std::lock_guard<std::mutex>lk(mt);
//         throw EmptyContainerError("Empty Container\n" , std::future_errc::no_state);
//     }

//     for(T v : data )
//     {
//         if(std::holds_alternative<CarPtr>(v))
//         {
//             const CarPtr ptr = std::get<CarPtr>(v);
//             if(ptr.get()->carBrand == brand )
//                 {
//                     std::cout<<*ptr<<"\n";
//                 }
//         }
//         else{
//             const BikePtr ptr = std::get<BikePtr>(v);
//             if(ptr.get()->bikeBrand() == brand){
//                 std::cout<<*ptr<<"\n";
//             }

//         }
//     }
// }


#endif // FUNCTIONALITIES_H
