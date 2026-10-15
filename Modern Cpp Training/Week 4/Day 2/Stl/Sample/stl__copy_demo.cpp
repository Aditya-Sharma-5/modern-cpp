
#include "/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Functionalities.h"
#include"/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Vehicle.h"
#include<algorithm>

template<typename T>
void Display(std::vector<T> data){
    for(const T &  t: data){
        std::cout<<t<<"\n";
    }
}

int main(){

    StackVehicles data1;
    RawPointers data2;
    SmartPointer data3;


    createObjects(data1);
    createObjects(data2);
    createObjects(data3);
///////////////////////////////////////////////////////

    StackVehicles result1 ;

    std::copy(
        data1.begin(),
        data1.end(),
        std::inserter(result1 , result1.begin()) // If you not use inserter , segmentation fault
    ) ;

    RawPointers result2;
    std::copy(
        data2.begin(),
        data2.end(),
        std::inserter(result2 , result2.begin())
    );

    SmartPointer result3;
    std::copy(
        data3.begin(),
        data3.end(),
        std::inserter(result3 , result3.begin())
    );

}