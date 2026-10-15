#include"Functionality.h"

int main(){

    DataContainer _data;

    CreateObject(_data);

    try{
        std::vector<EngineType> result = ContainerOfEngineType(_data);
        for(EngineType type : result){
            std::cout<<static_cast<int>(type)<<" ";
        }
        std::cout<<"\n";

    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }
    catch(const UnmatchConditionError& ex){
        std::cerr<<ex.what()<<"\n";
    }


    try{
        std::cout<<"At Least One Instance have Engine torque Below 110 : "<<AtLeastOneInstanceHaveTorqueBelow110(_data)<<"\n";
    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }


    try{
        ShowInstanceDetails(_data , 1);
    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }
    catch(const IndexOutOfBound& ex){
        std::cerr<<ex.what()<<"\n";
    }


    try{
        std::cout<<"The Number of Instances havine Engine Capacity  Over given capacity : "<<InstancesHavingHigherEngineCapacity(_data , 2.0f)<<"\n";
    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }
    catch(const UnmatchConditionError& ex){
        std::cerr<<ex.what()<<"\n";
    }


    try{
        DeallocateMemory(_data);
    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }

    return 0 ;


}