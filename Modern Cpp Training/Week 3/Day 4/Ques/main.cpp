#include<thread>
#include"Functionalities.h"

using ThreadList = std::list<std::thread>;

    //Static Assertion Failed -- means thread k parameter ya thread k syntax m glti h 
void MapThread(ThreadList& th , const DataContainer& data){


    th.emplace_back(&DisplayChassisTypeForGivenIds , std::ref(data) , std::list<std::string>{"1A" , "1c"});

    th.emplace_back(&MaxPriceOfFirstNInstances , std::ref(data) , 2);

    th.emplace_back(&CountVehicleOfGivenCategory , std::ref(data) , VehicleCategory::PRIVATE);

    th.emplace_back(&DisplayFirstNVehicle , std::ref(data) , 2);

    th.emplace_back(&AreAllCarPricesAboveGivenThreshold , std::ref(data) , 22000.0f);

}
void JoinThread(ThreadList& th){
    for(std::thread& t : th){
        if(t.joinable()){
            t.join();
        }
        else{
            std::cerr<<"Threads Instance not joinable\n";
        }
    }
}
int main(){
    DataContainer _data;
    ThreadList _threads;

    CreateObject(_data);
    MapThread(_threads , _data);
    JoinThread(_threads);
    return 0 ; 
}