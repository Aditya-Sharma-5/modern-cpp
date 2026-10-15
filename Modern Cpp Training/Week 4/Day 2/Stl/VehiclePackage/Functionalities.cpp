#include "Functionalities.h"

void createObjects(StackVehicles &data)
{
    data.emplace_back(101 , "Honda City" , 140000.0f , 5 , VehicleType::PRIVATE);
    data.emplace_back(102 , "Swift Dzire " , 70000.0f , 5 , VehicleType::PUBLIC_TRANSPORT);
    data.emplace_back(103 , "Scorpio" , 310000.0f , 7 , VehicleType::DEFENCE);
    data.emplace_back(104 , "Thar" , 350000.0f , 4 , VehicleType::PRIVATE);
    data.emplace_back(105 , "Xcent" , 90000.0f , 5 , VehicleType::PUBLIC_TRANSPORT);
}

void createObjects(RawPointers &data)
{
    data.emplace_back(new Vehicle(101 , "Honda City" , 140000.0f , 5 , VehicleType::PRIVATE));
    data.emplace_back(new Vehicle(102 , "Swift Dzire " , 70000.0f , 5 , VehicleType::PUBLIC_TRANSPORT));
    data.emplace_back(new Vehicle(103 , "Scorpio" , 310000.0f , 7 , VehicleType::DEFENCE));
    data.emplace_back(new Vehicle(104 , "Thar" , 350000.0f , 4 , VehicleType::PRIVATE));
    data.emplace_back(new Vehicle(105 , "Xcent" , 90000.0f , 5 , VehicleType::PUBLIC_TRANSPORT));
}

void createObjects(SmartPointer &data)
{
    data.emplace_back(std::make_shared<Vehicle>( 101 , "Honda City" , 140000.0f , 5 , VehicleType::PRIVATE));
    data.emplace_back(std::make_shared<Vehicle>( 102 , "Swift Dzire " , 70000.0f , 5 , VehicleType::PUBLIC_TRANSPORT));
    data.emplace_back(std::make_shared<Vehicle>( 103 , "Scorpio" , 310000.0f , 7 , VehicleType::DEFENCE));
    data.emplace_back(std::make_shared<Vehicle>( 104 , "Thar" , 350000.0f , 4 , VehicleType::PRIVATE));
    data.emplace_back(std::make_shared<Vehicle>( 105 , "Xcent" , 90000.0f , 5 , VehicleType::PUBLIC_TRANSPORT));
}
