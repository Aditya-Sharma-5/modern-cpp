/*
    This algorithms return iterator the first minimum element .
    The logic used for the comparision can be provided as COMPARATOR!!
*/

#include "/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Functionalities.h"
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

// Return type --> StackPointer::iterator
    auto itr = std::min_element(
        data1.begin(),
        data1.end(),
        // v1 will be lesser compared to v2 
        // if and only if v1's price is lesser than v2's price
        [](const Vehicle& v1 , const Vehicle& v2){return v1.price()< v2.price();}
    );
    std::cout<<" Stack Objects Minimum Price : "<<(*itr).price()<<"\n";
    std::cout<<" Stack Objects Id of Minimum Price : "<<(*itr).id()<<"\n";

    // Raw Pointer 
    auto itr1 = std::min_element(
        data2.begin(),
        data2.end(),
        // v1 will be lesser compared to v2 
        // if and only if v1's price is lesser than v2's price
        [](const Vehicle* v1 , const Vehicle* v2){return v1->price()< v2->price();}
    );
    std::cout<<" Raw Pointer Objects Minimum Price : "<<(*itr1)->price()<<"\n";
    std::cout<<" Raw Pointer Objects Id of Minimum Price : "<<(*itr1)->id()<<"\n";

    //Smart Pointer

    auto itr2 = std::min_element(
        data3.begin(),
        data3.end(),
        // v1 will be lesser compared to v2 
        // if and only if v1's price is lesser than v2's price
        [](const Vptr& v1 , const Vptr& v2){return v1->price()< v2->price();}
    );
    std::cout<<" Smart Pointer Objects Minimum Price : "<<(*itr2)->price()<<"\n";
    std::cout<<" Smart Pointer Objects Id of Minimum Price : "<<(*itr2)->id()<<"\n";
}

// g++ VehiclePackage/Vehicle.cpp VehiclePackage/Functionalities.cpp Sample/std::count_if_demo.cpp 