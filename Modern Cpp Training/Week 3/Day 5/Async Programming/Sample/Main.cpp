#include"Functionalities.h"
#include<future>
#include<thread>


int main(){

    VehicleContainer _vehicle ;
    EngineContainer _engine;

    CreateObject(_engine , _vehicle);


    // try
    // {
    //     VehicleContainer filtered_result = FilterVehicles(_vehicle , [](Vptr vh){return  vh->vehiclePrice()>85000;} );
    //     std::cout<<"The details of Filtered Vehicle Object : \n";
    //     showObject(filtered_result);
    // }
    // catch(const EmptyContainerError& ex)
    // {
    //     std::cerr<<ex.what()<<"\n";
    // }
    // catch(const UnmatchConditionError& ex)
    // {
    //     std::cerr<<ex.what()<<"\n";
    // }
    std::future<VehicleContainer>result =  std::async(&FilterVehicles , std::ref(_vehicle) , [](Vptr vh){return  vh->vehiclePrice()>85000;} );
    for (const Vptr& vh : result.get())
    {
        std::cout <<*vh<<"\n";
    }

    // try
    // {
    //     TransmissionType  transmission_result = FindTransmissionTypeById(_vehicle , "MH1234");
    //     std::cout<<"The Transmission Type of given Registration Number : "<<static_cast<int>(transmission_result)<<"\n\n";
    // }
    // catch(const EmptyContainerError& ex)
    // {
    //     std::cerr<<ex.what()<<"\n";
    // }
    // 

    std::future<TransmissionType>transmission_result = std::async(&FindTransmissionTypeById , std::ref(_vehicle)  , "MH1234");
    try{
        TransmissionType t = transmission_result.get();
        std::cout<<"The Transmission Type of given Registration Number : "<<static_cast<int>(t)<<"\n\n";
    }catch(const IdNotFoundError& ex)
    {
        std::cerr<<"Exception Msg : " <<ex.what()<<"\n";
        std::cerr<<"Exception Cause" <<ex.code()<<"\n";
    }
    

    // try
    // {
    //     auto fn = std::bind(&AboveThresholdTorqueVehicle , std::placeholders::_1 , 100.0f);

    //     VehicleContainer above_torque_result = fn(_vehicle);
    //     std::cout<<"The Vehicle Container having threshold above 100.0f is/are : \n";
    //     showObject(above_torque_result);
        
    // }
    // catch(const EmptyContainerError& ex)
    // {
    //     std::cerr<<ex.what()<<"\n";
    // }
    // catch(const UnmatchConditionError& ex)
    // {
    //     std::cerr<<ex.what()<<"\n";
    // }
    std::future<VehicleContainer>above_torque_result = std::async( std::bind(&AboveThresholdTorqueVehicle , std::placeholders::_1 , 210.0f) , std::ref(_vehicle));
    for (const Vptr& vh : above_torque_result.get())
    {
        std::cout <<*vh<<"\n";
    }
    // try
    // {
    //     DisplayTaxAmount(_vehicle , [](Vptr vh){return vh->vehiclePrice()*0.2;});
    //     std::cout<<"\n";
    // }
    // catch(const EmptyContainerError& ex)
    // {
    //     std::cerr<<ex.what()<<"\n";
    // }
    std::thread t3(&DisplayTaxAmount , std::ref(_vehicle) ,[](Vptr vh){return vh->vehiclePrice()*0.2;} );
    t3.join();

}