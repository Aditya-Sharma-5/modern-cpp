#include"Functionalities.h"

int main(){

    VehicleContainer _vehicle;
    EngineContainer _engine;

    CreateObject(_engine , _vehicle);
    // for(const Vehicle* ptr: _vehicle){
    //     std::cout << *ptr << std::endl;
    // }
    
    VehicleContainer f1_ans = FilterVehicles(_vehicle , [](const Vehicle* ptr){ return ptr->vehiclePrice() > 80000.0f;});
    auto itr1 = f1_ans.begin();
    while(itr1 != f1_ans.end()){
        std::cout << *(*itr1++) << std::endl;
    }

    DisplayTaxAmount(_vehicle, [](const Vehicle* ptr){ return ptr->vehiclePrice()* 0.2; });



    auto fn = std::bind(&AboveThresholdTorqueVehicle , std::placeholders::_1 , 100.0f);

}