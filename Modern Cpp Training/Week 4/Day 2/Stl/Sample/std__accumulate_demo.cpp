
/*
    This algorithms aggregates data by cumulative performing 
    a binary operation on the previous result and the next item from the container 


    accumate takes 2 parameters 
        - result upto current point 
        - next item from the data container 

    Binary Addition
    50     60    70
    init value : 0

    0    50     60      70
    |    |      |       |
    |    |      |       |
      0+50
      50       |        |
            110         |
                110+70
                        180 


*/
#include "/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Functionalities.h"
#include"/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 2/Stl/VehiclePackage/Vehicle.h"
#include<numeric>


int main(){
    StackVehicles data1;
    RawPointers data2;
    SmartPointer data3;


    createObjects(data1);
    createObjects(data2);
    createObjects(data3);
///////////////////////////////////////////////////////

    float total1 = std::accumulate(
        data1.begin(),
        data1.end(),
        0.0f,
        [](float answer_upto_current_point , const Vehicle& v){return answer_upto_current_point +v.price();}
    );
    std::cout<<" Stack Objects Total price : "<<total1<<"\n";



    float total2 = std::accumulate(
        data2.begin(),
        data2.end(),
        0.0f,
        [](float answer_upto_current_point , const Vehicle* v){return answer_upto_current_point +v->seatCount();}
    );
    std::cout<<" Raw Pointer Total Seat Count : "<<total2<<"\n";
}