#include "Functionality.h"


void CreateObject(DataContainer &data)
{
    data.push_back(new Engine("111" , 800 , EngineType::DIESEL , 2.5f , 125.0f));
    data.push_back(new Engine("112" , 650 , EngineType::HYBRID , 2.3f , 110.0f));
    data.push_back(new Engine("113" , 550 , EngineType::PETROL , 1.7f , 65.0f));
}


std::vector<EngineType> ContainerOfEngineType(const DataContainer &data)
{

    // Check Exception if data container is empty or Invalid Data
    if(data.empty()){
        throw EmptyContainerError("Data Container is Empty");
    }

    std::vector<EngineType> result;

    for(Engine* ptr : data)
    {
        if(ptr->horsepower()>600.0f && ptr->horsepower() >2.2f && ptr->engineTorque() > 80.0f){
            result.push_back(ptr->engineType());
        }
    }

    //Exception when the Condition is not satisfied
    if(result.empty()){
        throw UnmatchConditionError("Condition not Found");
    }
    return result;

}



bool AtLeastOneInstanceHaveTorqueBelow110(const DataContainer &data)
{
    // Check Exception if data container is empty or Invalid Data
    if(data.empty()){
        throw EmptyContainerError("Data Container is Empty");
    }

    for(Engine* ptr : data)
    {
        if(ptr->engineTorque() <110.0f)
        {
            return true;
        }
    }

    return false;

}



void ShowInstanceDetails(const DataContainer &data, int index)
{
    // Check Exception if data container is empty or Invalid Data
    if(data.empty())
    {
        throw EmptyContainerError("Data Container is Empty");
    }   

    //Check Exception that if index is invalid
    if(index>data.size()-1){
        throw IndexOutOfBound("Index is out of Bound");
    }

    for(int i = 0;i<data.size(); i++)
    {
        if(i == index)
        {
            std::cout<<*data[i]<<"\n";
        }
    }
}

int InstancesHavingHigherEngineCapacity(const DataContainer &data, float capacity)
{
    // Check Exception if data container is empty or Invalid Data
    if(data.empty())
    {
        throw EmptyContainerError("Data Container is Empty");
    }

    int countInstance = 0;

    for(Engine* ptr : data)
    {
        if(ptr->engineCapacity()>capacity)
        {
            countInstance++;
        }
    }

    //Exception when the Condition is not satisfied
    if(countInstance == 0){
        throw UnmatchConditionError("No Instance have High Capacity Than Given ");
    }

    return countInstance;

}

void DeallocateMemory(DataContainer &data)
{    
    // Check Exception if data container is empty or Invalid Data
    if(data.empty())
    {
        throw EmptyContainerError("Data Container is Empty");
    }

    for(Engine* ptr : data ){
        if(ptr)
        {
            delete ptr;
        }
    }
}
