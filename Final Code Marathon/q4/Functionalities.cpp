#include "Functionalities.h"
std::mutex mt;


void CreateObject(DataContainer &data, MiniContainer &mini)
{
    mini.push_back(VehicleSensorUnit(SensorUnitType::INTEGRATED , {23 , 33, 44, 58, 78} , 100));
    mini.push_back(VehicleSensorUnit(SensorUnitType::INTEGRATED , {21 , 31, 41, 55, 75} , 150));
    mini.push_back(VehicleSensorUnit(SensorUnitType::PLUG_IN , {28 , 38, 48, 58, 78} , 120));
    mini.push_back(VehicleSensorUnit(SensorUnitType::PLUG_IN , {22 , 32, 42, 54, 74} , 140));

    auto itr = mini.begin();

    if(itr != mini.end()){
        data.push_back(std::make_shared<Vehicle>("1A" ,"Dzire" , std::ref(*itr++) ));
    }

    if(itr != mini.end()){
        data.push_back(std::make_shared<Vehicle>("2A" ,"Verna" , std::ref(*itr++) ));
    }

    if(itr != mini.end()){
        data.push_back(std::make_shared<Vehicle>("3A" ,"THAR" , std::ref(*itr++) ));
    }

    if(itr != mini.end()){
        data.push_back(std::make_shared<Vehicle>("4A" ,"Bolero" , std::ref(*itr++) ));
    }

}

Set ContainerOfSesonUnitType(const DataContainer &data)
{
    //Exception Case for Empty Conatiner 
    if(data.empty()){
        std::lock_guard<std::mutex>lk(mt);
        throw EmptyContainerError("Data  is Empty !!\n" , std::future_errc::no_state);
    }

    Set result ; 
    

    std::transform(
        data.begin(),
        data.end(),
        std::inserter(result , result.begin()),
        [](Vptr v){
            return v.get()->vehicleSensorUnit().get().sensorUnitType();
        }
    );

// if no comdition satisfies the condition
    if(result.empty()){
        std::lock_guard<std::mutex>lk(mt);
        throw UnmatchConditionError("No Condition satisfies\n" , std::future_errc::no_state);
    }

    std::lock_guard<std::mutex>lk(mt);
    return result;

}

MiniContainer LastNSensorUnits(const DataContainer &data ,unsigned int N)
{
    //Exception Case for Empty Conatiner 
    if(data.empty()){
        std::lock_guard<std::mutex>lk(mt);
        throw EmptyContainerError("Data  is Empty !!\n" , std::future_errc::no_state);
    }


// If N is not valid
    if(N >data.size()  && N <=0)
    {
        std::lock_guard<std::mutex>lk(mt);
        throw InvalidInputError("Invalid Value of N \n" , std::future_errc::no_state);
    }

    MiniContainer result ;

    auto itr = data.begin();
    std::advance(itr , data.size()-N);
    std::transform(
        itr , 
        data.end(),
        std::inserter(result , result.begin()),
        [&](Vptr v){return v.get()->vehicleSensorUnit();}
    );

    std::lock_guard<std::mutex>lk(mt);
    return result;
}


float MaximumSensorReading(const DataContainer &data, std::string id)
{
    //Exception Case for Empty Conatiner 
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        throw EmptyContainerError("Data  is Empty !!\n" , std::future_errc::no_state);
    }

    auto itr = std::find_if
    (
        data.begin(),
        data.end(),
        [&](Vptr v){return v.get()->vehicleId() == id;}
    );

    // If Id is not found
    if(itr == data.end())
    {
        std::lock_guard<std::mutex>lk(mt);
        throw InvalidInputError{"Invalid Id \n" , std::future_errc::no_state}; 
    }

    std::array<float,5> result =  itr->get()->vehicleSensorUnit().get().sensorLast5Reading();

    auto ans = std::max_element(
        result.begin() , result.end()
    );

    std::lock_guard<std::mutex>lk(mt);
    return *ans;
}

int CountOfVehicleInstance(const DataContainer &data, Predicate fn)
{
    //Exception Case for Empty Conatiner 
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        throw EmptyContainerError("Data  is Empty !!\n" , std::future_errc::no_state);
    }

    std::lock_guard<std::mutex>lk(mt);
    return  std::count_if(
        data.begin(),
        data.end(),
        fn
    );

}
