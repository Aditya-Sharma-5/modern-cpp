#include "functionalities.h"


std::mutex mt;
void CreateObject(VrContainer &data)
{
    data.push_back(std::make_shared<Car>(70000 , "BMW" , VehicleType::SPORTS , 2 , 1.1));
    data.push_back(std::make_shared<Car>(85000 , "Tata" , VehicleType::PASSENGER , 4 , 1.2));
    data.push_back(std::make_shared<Bike>(10000 , "Honda" , VehicleType::COMMUTE , 90 , 2));
    data.push_back(std::make_shared<Bike>(10000 , "NINJA" , VehicleType::SPORTS , 220 , 2));
}

std::optional<float> AverageRTOChagesOFALLCars(const VrContainer &data)
{
    // Check Exception for EMpty Container 
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        throw EmptyContainerError("Empty Container\n" , std::future_errc::no_state);
    }

    float totalPrice = 0 ;
    int count = 0 ;

    for(Vr v : data){
        if(std::holds_alternative<CarPtr>(v)){
            const CarPtr ptr = std::get<CarPtr>(v);
            totalPrice += ptr.get()->CalculateRTOCharges();
            count++;
        }
    }
    if(count == 0 )
    {
        std::lock_guard<std::mutex>lk(mt);
        return std::nullopt;
    }

    std::lock_guard<std::mutex>lk(mt);
    return (totalPrice/count);
}


std::optional<std::vector<VehicleType>> AllVehiclesTypesOfBelowThresholdPrice(const VrContainer &data, float price)
{
    // Check Exception for EMpty Container 
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        throw EmptyContainerError("Empty Container\n" , std::future_errc::no_state);
    }

    std::vector<VehicleType> result ; 

    for(Vr v : data){
        if(std::holds_alternative<CarPtr>(v)){
            const CarPtr ptr = std::get<CarPtr>(v);
            if(ptr.get()->carPrice()<price)
            {
            result.push_back(ptr.get()->carVehicleType());
            }
        }
        else{
            const BikePtr ptr = std::get<BikePtr>(v);
            if(ptr.get()->getBikePrice()<price){
                result.push_back(ptr.get()->getBikeVehicleType());
            }
        }
    }

    if(result.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        return std::nullopt;
    }

    std::lock_guard<std::mutex>lk(mt);
    return result;

}


bool IsAllVariantsOfSameType(const VrContainer &data)
{
    // Check Exception for EMpty Container 
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        throw EmptyContainerError("Empty Container\n" , std::future_errc::no_state);
    }

// Assigning the values 
    VehicleType check ;
    if(std::holds_alternative<CarPtr>(data[0]))
    {
        const CarPtr ptr = std::get<CarPtr>(data[0]);
        check = ptr.get()->carVehicleType();
    }
    else
    {
        const BikePtr ptr = std::get<BikePtr>(data[0]);
        check = ptr.get()->getBikeVehicleType();
    }


// Checking for all objects 
    for(Vr v : data)
    {
        if(std::holds_alternative<CarPtr>(v))
        {
            const CarPtr ptr = std::get<CarPtr>(v);
            if(ptr.get()->carVehicleType() != check)
            {
                std::lock_guard<std::mutex>lk(mt);
                return false;
            }
        }
        else
        {
            const BikePtr ptr = std::get<BikePtr>(v);
            if(ptr.get()->getBikeVehicleType() != check)
            {
                std::lock_guard<std::mutex>lk(mt);
                return false;
            }
        }
    }

    std::lock_guard<std::mutex>lk(mt);
    return true;

}


std::optional<std::vector<BikePtr>> BikeInstancesHavingEngineCCAboveThreshold(const VrContainer &data, float cc)
{
    // Check Exception for EMpty Container 
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        throw EmptyContainerError("Empty Container\n" , std::future_errc::no_state);
    }

    std::vector<BikePtr> result ; 

    for(Vr v : data){
        if(std::holds_alternative<BikePtr>(v)){
            const BikePtr ptr = std::get<BikePtr>(v);
            if(ptr.get()->getBikeEngineCC()> cc){
                result.push_back(ptr);
            }
        }
    } 
    if(result.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        return std::nullopt;
    }

    std::lock_guard<std::mutex>lk(mt);
    return result;
}
