#include"functionalities.h"

int main(){
    VrContainer _data;

    try{
        CreateObject(_data);
    }
    catch(const InvalidInput& obj){
        std::cerr<<obj.what()<<"\n";
    }

    try{
       std::future<std::optional<float>> r1 = std::async(&AverageRTOChagesOFALLCars , std::ref(_data) );
       std::optional<float> r11 =  r1.get();
       if(r11.has_value()){
            float average_result = r11.value();
            std::cout<<average_result<<"\n";
       }
       else{
        std::cerr<<"Return NullOpt\n";
       }

    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }

    try{
       std::future<std::optional<std::vector<VehicleType>>> r2 = std::async(&AllVehiclesTypesOfBelowThresholdPrice , std::ref(_data) , 80000 );
       std::optional<std::vector<VehicleType>> r22 =  r2.get();
       
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }

    try{
        std::future<bool> r3 = std::async(&IsAllVariantsOfSameType , std::ref(_data) );
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }


    try{
       std::future<std::optional<std::vector<BikePtr>>> r4 = std::async(&BikeInstancesHavingEngineCCAboveThreshold, std::ref(_data) , 100.0 );
       r4.get();
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }

    // try{
    //     Display(_data, "BMW");
    // }
    // catch(const EmptyContainerError& obj){
    //     std::cerr<<obj.what()<<"\n";
    // }
}