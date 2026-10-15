#include"Functionalities.h"

int main(){
    DataContainer _data ;

    CreateObject(_data);

        std::future<std::optional<int>> r1 = std::async(&countOfEvEngine , std::ref(_data) , BatteryType::OTHER) ; 
        std::optional<int> r11 = r1.get();
        if(r11.has_value()){
            std::cout<<"The count is : "<<r11.value()<<"\n";
        }
        else{
            std::cerr<<"No output!!\n";
        }


        std::future<std::optional<bool>> r2 = std::async(&IsAllInstancesOfICEngineAbove500HP , std::ref(_data)) ; 
        std::optional<bool> r22 = r2.get();
        if(r22.has_value()){
            std::cout<<"All instances is Have Same Hp above 500 : "<<r22.value()<<"\n";
        }
        else{
            std::cerr<<"No output!!\n";
        }

        
        std::future<std::optional<float>> r3 = std::async(&AverageAnnualEngineMaintenanceCost , std::ref(_data)) ; 
        std::optional<float> r33 = r3.get();
        if(r33.has_value()){
            std::cout<<"The Average Annual Engine Maintanence Cost : "<<r33.value()<<"\n";
        }
        else{
            std::cerr<<"No output!!\n";
        } 


        std::future<std::optional<float>> r4 = std::async(&EVEngineTorqueOfGivenID , std::ref(_data) , "3A") ; 
        std::optional<float> r44 = r4.get();
        if(r44.has_value()){
            std::cout<<"Engine torque of given id : "<<r44.value()<<"\n";
        }
        else{
            std::cerr<<"No output!!\n";
        }

}