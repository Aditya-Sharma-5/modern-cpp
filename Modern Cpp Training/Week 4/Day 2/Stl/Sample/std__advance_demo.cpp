/*
    Advance return type is void 
    No copies are done 
    Only modifies the original iterator
*/

#include "/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Functionalities.h"
#include"/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Vehicle.h"
#include<algorithm>
#include<numeric>


/*
    It odifies the input iterator by shifting it by given distance
*/
int main(){

    StackVehicles data1;
    RawPointers data2;
    SmartPointer data3;


    createObjects(data1);
    createObjects(data2);
    createObjects(data3);
///////////////////////////////////////////////////////

    auto itr = data1.begin();

    std::advance(
        // data1.begin(),  // it gives error , as it works only lvalve
        itr,
        2                  // jump by 2 position
    );

    float total =  std::accumulate(
        itr,
        data1.end(),
        0.0f,
        [](float answer_upto_current_position , const Vehicle& v){return answer_upto_current_position + v.price();}
    );
    std::cout<<"The Total price of last 3 objects : "<<total<<"\n";

}