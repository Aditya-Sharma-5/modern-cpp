#include "Functionalities.h"

void CreateObject(EngineContainer &engine, DataContainer &vehicle)
{
    engine.push_back(Engine(400, 150.0f));
    engine.push_back(Engine(550, 220.0f));
    engine.push_back(Engine(520, 200.0f));
    engine.push_back(Engine(580, 250.0f));

    auto itr = engine.begin();

    //If itr is not equal to the end of objects
    if(itr!= engine.end()){
    vehicle.emplace("DL1987" , std::make_shared<Vehicle>("DL1987" , 80000.0f , VehicleType::PERSONAL , 2.5f , 1.2f , TransmissionType::AMT , VehicleFuelType::DIESEL,std::ref(*itr++) ));
    }

    //If itr is not equal to the end of objects
    if(itr!= engine.end()){
    vehicle.emplace("MH1234" ,std::make_shared<Vehicle>("MH1234" , 90000.0f , VehicleType::RENTAL , 3.5f , 1.8f , TransmissionType::MANUAL , VehicleFuelType::DIESEL,std::ref(*itr++) ));
    }
    
    //If itr is not equal to the end of objects
    if(itr!= engine.end()){
    vehicle.emplace("UP1911" ,std::make_shared<Vehicle>("UP1911" , 84000.0f , VehicleType::T_PERMIT, 2.5f , 1.2f , TransmissionType::MANUAL , VehicleFuelType::PETROL,std::ref(*itr++) ));
    }

    //If itr is not equal to the end of objects
    if(itr!= engine.end()){
    vehicle.emplace("HR6334" ,std::make_shared<Vehicle>("HR6334" , 95000.0f , VehicleType::PERSONAL , 3.0f , 1.5f , TransmissionType::DC_AUTOMATIC , VehicleFuelType::ALTERNATIVE_FUEL,std::ref(*itr++) ));
    }

}



VehicleContainer FilterVehicles(const DataContainer &vehicle, Predicate fn)
{
    if(vehicle.empty()){
        throw EmptyContainerError("Data Container is Empty!!!\n");
    }

    VehicleContainer result ; 

    for(const std::pair<std::string , Vptr>&vh:vehicle){
        if(fn(vh.second)){
            result.push_back(vh.second);
        }
    }

    if(result.empty()){
        throw  UnmatchConditionError("No vehicle object is fulfill the condition\n");
    }
    return result;
}



TransmissionType FindTransmissionTypeById(const DataContainer &vehicle, std::string id)
{
    if(vehicle.empty()){
        throw EmptyContainerError("Data Container is Empty!!!\n");
    }

    for(const std::pair<std::string , Vptr>&vh : vehicle){
        if(vh.second->vehicleRegNumber() == id){
            return vh.second->vehicleTransmissionType();
        }
    }
    throw IdNotFoundError("Invalid Id!!" , std::future_errc::no_state) ;
}



VehicleContainer AboveThresholdTorqueVehicle(const DataContainer &vehicle, float threshold)
{
    if(vehicle.empty()){
        throw EmptyContainerError("Data Container is Empty!!!\n");
    }

    VehicleContainer result ; 

    for(const std::pair<std::string , Vptr>&vh : vehicle){
        if(vh.second->engineRef().get().engineTorque() > threshold){
            result.push_back(vh.second);
        }
    }    
    
    
    if (result.empty())
    {
        throw UnmatchConditionError("No Vehicle object have Engine Torque above given threshold\n");
    }
 
    return result;
}


void showObject(const DataContainer &vehicle)
{
    if(vehicle.empty())
    {
        throw EmptyContainerError("Data Container is Empty!!!\n");
    }
        
    for (const std::pair<std::string , Vptr>&vh: vehicle)
    {
        std::cout <<*vh.second<<"\n";
    }
    std::cout<<"\n";

}


void DisplayTaxAmount(const DataContainer &vehicle, UnaryFunction fn)
{
    if(vehicle.empty())
    {
        throw EmptyContainerError("Data Container is Empty!!!\n");
    }
 
    for (const std::pair<std::string , Vptr>&vh: vehicle)
    {
        std::cout<<"The Tax anount of this Vehicle Object : " << fn(vh.second)<<"\n";
    }
}
 
