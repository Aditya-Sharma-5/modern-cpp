
#include "/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Functionalities.h"
#include"/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Vehicle.h"
#include<algorithm>

/*
    Return true if atleast 1 objects in the input range satisfy the predicate . 
    EVEN IN A SINGLE FAIL CONDITION , return false
*/
int main(){
    StackVehicles data1;
    RawPointers data2;
    SmartPointer data3;


    createObjects(data1);
    createObjects(data2);
    createObjects(data3);
///////////////////////////////////////////////////////
    bool flag1 = std::any_of(
        data1.begin(),
        data1.end(),
        [](const Vehicle& v){return v.seatCount()>4;}
    );
    std::cout<<" Stack Objects : "<<std::boolalpha<<flag1<<"\n";

    // Raw Pointer 
    bool flag2 = std::any_of(
        data2.begin(),
        data2.end(),
        [](const Vehicle* v){return v->seatCount()>4;}
    );
    std::cout<<" Raw Pointers Objects : "<<std::boolalpha<<flag2<<"\n";

    //Smart Pointers
    bool flag3 = std::any_of(
        data3.begin(),
        data3.end(),
        [](const Vptr& v){return v->seatCount()>4;}
    );
    std::cout<<" Smart Pointers Objects : "<<std::boolalpha<<flag3<<"\n";
}

// g++ VehiclePackage/Vehicle.cpp VehiclePackage/Functionalities.cpp Sample/std::count_if_demo.cpp 