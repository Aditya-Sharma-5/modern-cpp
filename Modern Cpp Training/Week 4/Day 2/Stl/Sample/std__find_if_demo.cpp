/*
    find_if return the iterator to the first object which satisfies the given conditions

    IF NONE OF THE OBJECT SATISFY THE CONDITION , std::find_if return end iterators
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

    auto itr = std::find_if(
        data1.begin(),
        data1.end(),
        [](const Vehicle& v){return v.id() == 103;}
    );
    if(itr != data1.end()){
        std::cout<<"Price of the Vehicle  with this id is : "<<(*itr).price()<<"\n";
    }
    else{
        std::cerr<<"Id not found\n";
    }
// -------------------------------------------------------------------------------------------
    auto itr1 = std::find_if(
        data2.begin(),
        data2.end(),
        [](const Vehicle* v){return v->id() == 103;}
    );
    if(itr1 != data2.end()){
        std::cout<<"Price of the Vehicle  with this id is : "<<(*itr1)->price()<<"\n";
    }
    else{
        std::cerr<<"Id not found\n";
    }

// -------------------------------------------------------------------------------------------
    auto itr2 = std::find_if(
        data3.begin(),
        data3.end(),
        [](const Vptr& v){return v->id() == 103;}
    );
    if(itr2 != data3.end()){
        std::cout<<"Price of the Vehicle  with this id is : "<<(*itr2)->price()<<"\n";
    }
    else{
        std::cerr<<"Id not found\n";
    }
}