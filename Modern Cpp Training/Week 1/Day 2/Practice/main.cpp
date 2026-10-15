#include"Functionalities.h"
#include<iostream>

int main(){
    Container _data;
    createObject(_data);
    // showData(_data);

    std::cout<<findEngineHorsepower(_data , "1e")<<"\n";


    std::cout<<"Cars having Engine Torque over 80 N.M \n";
    Container _engineTorque = aboveEngineTorque(_data);
    showData(_engineTorque);

    std::cout<<"Cars having Car Type : SEDAN \n";
    Container _matchedCarType = matchCarType(_data , CarType::SEDAN);
    showData(_matchedCarType);

    std::cout<<"Average Engine HorsePower : "<<averageEngineHorsepower(_data)<<"\n";

    std::cout<<"Car Id having lowest Car Price : "<<findCarId(_data)<<"\n";

    std::cout<<"Combined Price : "<<combinedPrice(_data)<<"\n";

    deleteObject(_data);


    return 0 ;
}