#include "Functionalities.h"

void CreateObject(EngineContainer &engine, VehicleContainer &vehicle)
{
    engine.push_back(Engine(400, 150.0f));
    engine.push_back(Engine(550, 220.0f));

    auto  itr = engine.begin();   // Here auto = std::list<Engine>::iterator

    //If itr is not equal to the end of objects
    if(itr!= engine.end()){
    vehicle.push_back(new Vehicle("DL1987" , 80000.0f , VehicleType::PERSONAL , 2.5f , 1.2f , TransmissionType::AMT , VehicleFuelType::DIESEL,std::ref(*itr++) ));
    }

    //If itr is not equal to the end of objects
    if(itr!= engine.end()){
    vehicle.push_back(new Vehicle("Mh1234" , 90000.0f , VehicleType::RENTAL , 3.5f , 1.8f , TransmissionType::MANUAL , VehicleFuelType::DIESEL,std::ref(*itr++) ));
    }

}



VehicleContainer FilterVehicles(const VehicleContainer &vehicle, Predicate fn)
{
    if(vehicle.empty()){
        throw EmptyContainerError("Data Container is Empty");
    }

    VehicleContainer result ; 

    for(Vehicle* vh:vehicle){
        if(fn(vh)){
            result.push_back(vh);
        }
    }

    if(result.empty()){
        throw ConditionNotMatchError("No Condition is matched");
    }
    return result;
}



TransmissionType FindTransmissionTypeById(const VehicleContainer &vehicle, std::string id)
{
    if(vehicle.empty()){
        throw EmptyContainerError("Data Container is Empty");
    }

    for(Vehicle* vh : vehicle){
        if(vh->vehicleRegNumber() == id){
            return vh->vehicleTransmissionType();
        }
    }

    throw IdNotFoundError("Invalid Id");
}



VehicleContainer AboveThresholdTorqueVehicle(const VehicleContainer &vehicle, float threshold)
{
    if(vehicle.empty())
    {
        throw EmptyContainerError("Data Container is Empty");
    }

    VehicleContainer result ; 

    for(Vehicle* vh : vehicle){
        if(vh->engineRef().get().engineTorque() > threshold){
            result.push_back(vh);
        }
    }    
    
    
    if (result.empty())
    {
        throw ConditionNotMatchError("No Vehicle above Given Threshold Torque is found") ;
    }
 
    return result;

}




void DisplayTaxAmount(const VehicleContainer & vehicle, UnaryFunction fn)
{
    if ( vehicle.empty())
    {
        throw EmptyContainerError("Data Container is Empty");
    }
 
    for (Vehicle *vh :  vehicle)
    {
        std::cout << fn(vh) << std::endl;
    }
}





 
