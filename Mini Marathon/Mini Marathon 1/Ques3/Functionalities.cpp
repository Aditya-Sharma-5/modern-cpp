#include "Functionalities.h"

void CreateObject(Container &data)
{
    data.push_back(new ElectricVehicle("1A" , "Dzire" , BatteryType::LITHIUM_ION , 50.0f , 
                                                                        new Motor(12.0f , 330 , 250)));

    data.push_back(new ElectricVehicle("1B" , "Verna" , BatteryType::NICKEL_METAL_HYDRIDE , 55.0f , 
                                                                        new Motor(10.0f , 270 , 210)));

    data.push_back(new ElectricVehicle("1C" , "AMG" , BatteryType::NICKEL_METAL_HYDRIDE , 60.0f , 
                                                                        new Motor(8.0f , 330 , 300)));

    data.push_back(new ElectricVehicle("1D" , "Mustang" , BatteryType::LITHIUM_ION , 70.0f , 
                                                                        new Motor(9.0f , 320 , 310)));
}


float MaxTorqueOrMaxPowerOfID(const Container &data, std::string check_id)
{
    //Checking Exception for Empty Container
    if(data.empty()){
        throw EmptyContainerError("Data Container is Empty");
    }

    for(ElectricVehicle* ptr : data)
    {
        if(ptr && ptr->id() == check_id)
        {
            if(ptr->batteryCapacity()>= 30.3f)
            {
                return ptr->motor()->maxTorque();
            }
            else
            {
                return ptr->motor()->maxPower();
            }
        }
    }
    throw IdNotFoundError("Id not found");

}


void DisplayBatteryDrainRate(const Container &data)
{
    //Checking Exception for Empty Container
    if(data.empty()){
        throw EmptyContainerError("Data Container is Empty");
    }

    for(ElectricVehicle* ptr : data){
        if(ptr->batteryType() == BatteryType::LITHIUM_ION)
        {
            std::cout<<"The Value of Battery Drain is : "<<(0.1 * ptr->batteryCapacity())<<"\n";
        }
        else
        {
            std::cout<<"The Value of Battery Drain is : "<<(   (0.1* ptr->motor()->maxTorque())  +  (0.2* ptr->motor()->maxPower())   )/100<<"\n";
        }
    }

}


std::vector<float> ContainerStoringResultOfOperatorOverloading(const Container &data)
{
    //Checking Exception for Empty Container
    if(data.empty()){
        throw EmptyContainerError("Data Container is Empty");
    }

    std::vector<float> result ; 

    for(int i = 0; i<data.size()-1; i++){
        result.push_back(*data[i] + *data[i+1]);
    }

    return result;
}

void DeallocateMemory(Container &data)
{
    //Checking Exception for Empty Container
    if(data.empty()){
        throw EmptyContainerError("Data Container is Empty");
    }
    for(ElectricVehicle* ptr : data){
        if(ptr){
            if(ptr->motor() !=nullptr){
                delete ptr->motor();
            }
            delete ptr;
        }

    }
}
