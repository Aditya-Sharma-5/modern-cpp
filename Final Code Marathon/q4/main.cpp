#include"Functionalities.h"

int main(){
    DataContainer _data;
    MiniContainer _mini;

    CreateObject(_data , _mini);

    auto fn = std::bind(&LastNSensorUnits , std::ref(_data) , 3);
    try{
        std::future<MiniContainer> r1 = std::async(fn);

        for(auto v : r1.get()){
                std::cout<<v<<"\n";
        }
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }
    catch(const InvalidInputError& obj){
        std::cerr<<obj.what()<<"\n";
    }

    try{
        std::future<Set> r2 = std::async(&ContainerOfSesonUnitType , std::ref(_data) );
        for(SensorUnitType val : r2.get()){
                std::cout<<static_cast<int>(val)<<"   ";
        }
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }


    try{
        std::future<float> r3 = std::async(&MaximumSensorReading , std::ref(_data) , "2A");
        std::cout<<"The Maximum Sensor Reading is : "<<r3.get()<<"\n";
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }
    catch(const InvalidInputError& obj){
        std::cerr<<obj.what()<<"\n";
    }


    try{
        std::future<int> r4 = std::async(&CountOfVehicleInstance , std::ref(_data) , [&](Vptr v){return v.get()->vehicleSensorUnit().get().sensorThresholValue()>130;});
        std::cout<<"The count of Vehicle Instances is : "<<r4.get()<<"\n";
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }
}