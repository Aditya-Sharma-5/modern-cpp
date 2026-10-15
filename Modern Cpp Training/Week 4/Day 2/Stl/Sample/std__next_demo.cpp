
#include "/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Functionalities.h"
#include"/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Vehicle.h"
#include<algorithm>
#include<numeric>

/*
    next will shift the input iterator by given position N (by default 1)
    The function return the iterator 
*/
/*
    a1      a2      a3      a4      a5
    find the sum of last 3 objects 
*/
int main(){

    StackVehicles data1;
    RawPointers data2;
    SmartPointer data3;


    createObjects(data1);
    createObjects(data2);
    createObjects(data3);
///////////////////////////////////////////////////////
    auto itr = std::next(
        data1.begin(),
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

/*
    _InputIterator next<_InputIterator>
    (_InputIterator __x, std::iterator_traits<_InputIterator>::difference_type __n = 1)
*/