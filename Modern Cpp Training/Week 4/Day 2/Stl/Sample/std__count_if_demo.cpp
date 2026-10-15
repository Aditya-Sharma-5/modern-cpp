// #include"VehiclePackage/Functionalities.h"
#include "/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Functionalities.h"
// #include"VehiclePackage/Vehicle.h"
#include"/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Vehicle.h"
#include<algorithm>


int main(){
    StackVehicles data1;
    RawPointers data2;
    SmartPointer data3;


    createObjects(data1);
    createObjects(data2);
    createObjects(data3);
///////////////////////////////////////////////////////
    std::size_t count1 = std::count_if(
        data1.begin(),
        data1.end(),
        [](const Vehicle& v){return v.seatCount()>4;}
    );
    std::cout<<"Count of Stack Objects : "<<count1<<"\n";

    // Raw Pointer 
    std::size_t count2 = std::count_if(
        data2.begin(),
        data2.end(),
        [](const Vehicle* v){return v->seatCount()>4;}
    );
    std::cout<<"Count of Raw Pointers Objects : "<<count2<<"\n";

    //Smart Pointers
    std::size_t count3 = std::count_if(
        data3.begin(),
        data3.end(),
        [](const Vptr& v){return v->seatCount()>4;}
    );
    std::cout<<"Count of Smart Pointers Objects : "<<count3<<"\n";
}

// g++ VehiclePackage/Vehicle.cpp VehiclePackage/Functionalities.cpp Sample/std::count_if_demo.cpp 