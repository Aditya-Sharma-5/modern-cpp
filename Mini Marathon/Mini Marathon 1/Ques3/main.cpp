#include"Functionalities.h"

int main(){
    Container _data;

    try{
        CreateObject(_data);
    }
    catch(const InvalidInputError& ex){
        std::cerr<<ex.what()<<"\n";
    }

    try{
        float result_max_torque_power = MaxTorqueOrMaxPowerOfID(_data , "1B");
        std::cout<<"Max Torque or Max Power based on ID : "<<result_max_torque_power<<"\n";
    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }
    catch(const IdNotFoundError& ex){
        std::cerr<<ex.what()<<"\n";
    }

    
    try{
        DisplayBatteryDrainRate(_data);
    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }

    
    try{
        std::vector<float>result = ContainerStoringResultOfOperatorOverloading(_data );
        int i = 1;
        for(float f : result){
            std::cout<<"Result of Instance "<<i<<" and "<<i+1<<" is : "<<f<<"\n"; 
            i++;
        }
    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }

        
    try{
        DeallocateMemory(_data);
    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }


}