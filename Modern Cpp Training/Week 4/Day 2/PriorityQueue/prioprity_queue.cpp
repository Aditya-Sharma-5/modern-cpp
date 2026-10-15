
#include "/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Functionalities.h"
#include"/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Vehicle.h"
#include<queue>


int main(){

    StackVehicles data1;
    RawPointers data2;
    SmartPointer data3;


    createObjects(data1);
    createObjects(data2);
    createObjects(data3);
///////////////////////////////////////////
    auto comp = [](const Vehicle& v1 , const Vehicle& v2){return v1.price() <v2.price();};

    std::priority_queue<Vehicle , std::vector<Vehicle> , decltype(comp)>pq(data1.begin() , data1.end() , comp);

}