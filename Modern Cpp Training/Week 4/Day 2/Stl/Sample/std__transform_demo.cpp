/*
    map function equivalent 
    Supply a unary function to be applied on each item on the data container 
    New Values which will be genertaed  can be stored in a new container or existing container 
*/


#include "/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Functionalities.h"
#include"/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Vehicle.h"
#include<algorithm>

/*
    Transform the price of vehicles into discounted price
*/
template<typename T>
void Display(const std::vector<T>& data){
    for(const T& val : data){
        std::cout<<val<<"\t";
    }
}


int main(){

    StackVehicles data1;
    RawPointers data2;
    SmartPointer data3;

    std::vector<float>result1;
    std::vector<float>result2;
    std::vector<float>result3;

    createObjects(data1);
    createObjects(data2);
    createObjects(data3);
///////////////////////////////////////////////////////

    // If your result vector is empty ,it show segmentation fault , allocate memory before it
    std::transform(
        data1.begin(),
        data1.end(),
        std::inserter(result1 , result1.begin()) ,
        [](const Vehicle& v){return v.price()*0.9f;}
    );
    std::cout<<"Answer of Stack Objects : ";
    Display(result1);
    std::cout<<"\n";

    std::transform(
        data2.begin(),
        data2.end(),
        std::inserter(result2 , result2.begin()) ,
        [](const Vehicle* v){return v->price()*0.9f;}
    );
    std::cout<<"Answer of Raw Pointer Objects : ";
    Display(result2);
    std::cout<<"\n";

    std::transform(
        data3.begin(),
        data3.end(),
        std::inserter(result3 , result3.begin()) ,
        [](const Vptr& v){return v->price()*0.9f;}
    );
    std::cout<<"Answer of Shared Pointer Objects : ";
    Display(result3);
    std::cout<<"\n";
}