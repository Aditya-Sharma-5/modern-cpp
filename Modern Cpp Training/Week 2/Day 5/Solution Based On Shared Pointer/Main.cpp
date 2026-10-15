#include"Functionalities.h"
int main(){

    VehicleContainer _vehicle ;
    EngineContainer _engine;

    CreateObject(_engine , _vehicle);


    try
    {
        VehicleContainer filtered_result = FilterVehicles(_vehicle , [](Vptr vh){return  vh->vehiclePrice()>85000;} );
        std::cout<<"The details of Filtered Vehicle Object : \n";
        showObject(filtered_result);
    }
    catch(const EmptyContainerError& ex)
    {
        std::cerr<<ex.what()<<"\n";
    }
    catch(const UnmatchConditionError& ex)
    {
        std::cerr<<ex.what()<<"\n";
    }


    try
    {
        TransmissionType  transmission_result = FindTransmissionTypeById(_vehicle , "MH1234");
        std::cout<<"The Transmission Type of given Registration Number : "<<static_cast<int>(transmission_result)<<"\n\n";
    }
    catch(const EmptyContainerError& ex)
    {
        std::cerr<<ex.what()<<"\n";
    }
    catch(const IdNotFoundError& ex)
    {
        std::cerr<<ex.what()<<"\n";
    }

    
    try
    {
        auto fn = std::bind(&AboveThresholdTorqueVehicle , std::placeholders::_1 , 100.0f);

        VehicleContainer above_torque_result = fn(_vehicle);
        std::cout<<"The Vehicle Container having threshold above 100.0f is/are : \n";
        showObject(above_torque_result);
        
    }
    catch(const EmptyContainerError& ex)
    {
        std::cerr<<ex.what()<<"\n";
    }
    catch(const UnmatchConditionError& ex)
    {
        std::cerr<<ex.what()<<"\n";
    }


    try
    {
        DisplayTaxAmount(_vehicle , [](Vptr vh){return vh->vehiclePrice()*0.2;});
        std::cout<<"\n";
    }
    catch(const EmptyContainerError& ex)
    {
        std::cerr<<ex.what()<<"\n";
    }

}