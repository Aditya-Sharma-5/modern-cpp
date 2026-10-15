#include "Functionalities.h"

void CreateObject(EngineContainer &engine, VehicleContainer &vehicle)
{
    engine.push_back(Engine(400, 150.0f));
    engine.push_back(Engine(550, 220.0f));
    engine.push_back(Engine(520, 200.0f));
    engine.push_back(Engine(580, 250.0f));

    auto itr = engine.begin();

    //If itr is not equal to the end of objects
    if(itr!= engine.end()){
    vehicle.push_back(std::make_shared<Vehicle>("DL1987" , 80000.0f , VehicleType::PERSONAL , 2.5f , 1.2f , TransmissionType::AMT , VehicleFuelType::DIESEL,std::ref(*itr++) ));
    }

    //If itr is not equal to the end of objects
    if(itr!= engine.end()){
    vehicle.push_back(std::make_shared<Vehicle>("MH1234" , 90000.0f , VehicleType::RENTAL , 3.5f , 1.8f , TransmissionType::MANUAL , VehicleFuelType::DIESEL,std::ref(*itr++) ));
    }
    
    //If itr is not equal to the end of objects
    if(itr!= engine.end()){
    vehicle.push_back(std::make_shared<Vehicle>("UP1911" , 84000.0f , VehicleType::T_PERMIT, 2.5f , 1.2f , TransmissionType::MANUAL , VehicleFuelType::PETROL,std::ref(*itr++) ));
    }

    //If itr is not equal to the end of objects
    if(itr!= engine.end()){
    vehicle.push_back(std::make_shared<Vehicle>("HR6334" , 95000.0f , VehicleType::PERSONAL , 3.0f , 1.5f , TransmissionType::DC_AUTOMATIC , VehicleFuelType::ALTERNATIVE_FUEL,std::ref(*itr++) ));
    }

}



VehicleContainer FilterVehicles(const VehicleContainer &vehicle, Predicate fn)
{
    if(vehicle.empty()){
        throw EmptyContainerError("Data Container is Empty!!!\n");
    }

    VehicleContainer result ; 

    for(const Vptr& vh:vehicle){
        if(fn(vh)){
            result.push_back(vh);
        }
    }

    if(result.empty()){
        throw  UnmatchConditionError("No vehicle object is fulfill the condition\n");
    }
    return result;
}



TransmissionType FindTransmissionTypeById(const VehicleContainer &vehicle, std::string id)
{
    if(vehicle.empty()){
        throw EmptyContainerError("Data Container is Empty!!!\n");
    }

    for(const Vptr& vh : vehicle){
        if(vh->vehicleRegNumber() == id){
            return vh->vehicleTransmissionType();
        }
    }
    throw IdNotFoundError("Invalid Id!!!\n") ;
}



VehicleContainer AboveThresholdTorqueVehicle(const VehicleContainer &vehicle, float threshold)
{
    if(vehicle.empty()){
        throw EmptyContainerError("Data Container is Empty!!!\n");
    }

    VehicleContainer result ; 

    for(const std::shared_ptr<Vehicle>& vh : vehicle){
        if(vh->engineRef().get().engineTorque() > threshold){
            result.push_back(vh);
        }
    }    
    
    
    if (result.empty())
    {
        throw UnmatchConditionError("No Vehicle object have Engine Torque above given threshold\n");
    }
 
    return result;
}


void showObject(const VehicleContainer &vehicle)
{
    if(vehicle.empty())
    {
        throw EmptyContainerError("Data Container is Empty!!!\n");
    }
        
    for (const Vptr& vh : vehicle)
    {
        std::cout <<*vh<<"\n";
    }
    std::cout<<"\n";

}


void DisplayTaxAmount(const VehicleContainer &vehicle, UnaryFunction fn)
{
    if(vehicle.empty())
    {
        throw EmptyContainerError("Data Container is Empty!!!\n");
    }
 
    for (const Vptr& vh : vehicle)
    {
        std::cout<<"The Tax anount of this Vehicle Object : " << fn(vh)<<"\n";
    }
}
 
