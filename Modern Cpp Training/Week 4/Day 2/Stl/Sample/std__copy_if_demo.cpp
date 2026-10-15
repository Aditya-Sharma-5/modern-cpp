
#include "/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Functionalities.h"
#include"/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Vehicle.h"
#include<algorithm>

/*
    This element copies N items from the input range into the output starting from output iterat
*/
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

    std::copy_if(
        data1.begin(),
        data1.end(),
        std::inserter(result1 , result1.begin()),
        [](const Vehicle& v){return v.price()>80000;}
    );

    std::copy_n(
        data1.begin(),
        2,
        std::inserter(result1 , result1.begin()) // If you not use inserter , segmentation fault
    ) ;

    RawPointers result2;
    std::copy_n(
        data2.begin(),
        3,
        std::inserter(result2 , result2.begin())
    );

    SmartPointer result3;
    auto itr = data3.begin();
    std::advance(itr , 2);

    // Now this will copy 3rd & 4th object of data3 into result3
    std::copy_n(
        itr,
        2,
        std::inserter(result3 , result3.begin())
    );

}