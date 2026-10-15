#include "Operation.h"

Operation *Operation::object{nullptr};

Operation *Operation::GetInstance()
{
    if (object)
    {
        return object;
    }
    object = new Operation();
    return object;
}

void Operation::CreateObjects(Container& data)
{
    data.emplace_back(std::make_shared<Automobile>("AM101", AutomobileType::REGULAR, 1000.0f, 4, 1000));
    data.emplace_back(std::make_shared<EvCar>(1011.0f, 1100.0f, ChargingType::AC));
    data.emplace_back(std::make_shared<Automobile>("AM102", AutomobileType::REGULAR, 2000.0f, 2, 2000));
    data.emplace_back(std::make_shared<EvCar>(2022.0f, 2200.0f, ChargingType::DC));
    data.emplace_back(std::make_shared<Automobile>("AM102", AutomobileType::TRANSPORT, 3000.0f, 4, 3000));
}

void Operation::AverageGSTOfEvCars(Container& data)
{
    if (data.empty())
    {
        throw ExceptionMessage("EMPTY DATAA!!");
    }

    bool notfound{true};
    float sum{0};
    std::size_t cnt{0};
    for (auto &itr : data)
    {
        if (std::holds_alternative<EvCarPtr>(itr))
        {
            notfound = false;
            sum += std::get<0>(itr)->CalculateGST();
            cnt++;
        }
    }

    if (notfound)
    {
        throw ExceptionMessage("No Instance of EvCar");
    }
    std::lock_guard<std::mutex> lt(mt);
    std::cout << "Average GST of EvCars : " << (float)sum / cnt << std::endl;
}

void Operation::AutomobilesAboveSeatCount4(Container& data)
{
    if (data.empty())
    {
        throw ExceptionMessage("EMPTY DATAA!!");
    }
    bool notfound{true};

    std::size_t cnt{0};
    for (auto &itr : data)
    {
        if (std::holds_alternative<AutomobilePtr>(itr) && std::get<1>(itr)->seatCount() >= 4)
        {
            cnt++;
            notfound=false;
        }
    }

    if (notfound)
    {
        throw ExceptionMessage("No Instance of AutoMobile");
    }
    std::lock_guard<std::mutex> lt(mt);
    std::cout << "Count of Automobile instances with seat count above 4 : " << cnt << std::endl;
}

void Operation::AverageAutomobilePrice(Container& data)
{
    if (data.empty())
    {
        throw ExceptionMessage("EMPTY DATAA!!");
    }

    bool notfound{true};
    float sum{0};
    std::size_t cnt{0};
    for (auto &itr : data)
    {
        if (std::holds_alternative<AutomobilePtr>(itr))
        {
            notfound = false;
            sum += std::get<1>(itr)->price();
            cnt++;
        }
    }

    if (notfound)
    {
        throw ExceptionMessage("No Instance of Automobile");
    }
    std::lock_guard<std::mutex> lt(mt);
    std::cout << "Average Price of Automobile : " << (float)sum / cnt << std::endl;
}

void Operation::IfAnyDCType(Container& data)
{
    if (data.empty())
    {
        throw ExceptionMessage("EMPTY DATAA!!");
    }
    bool found{false};

    for (auto &itr : data)
    {
        if (std::holds_alternative<EvCarPtr>(itr) && std::get<0>(itr)->chargingType() == ChargingType::DC)
        {
            found = true;
        }
    }
    std::lock_guard lt(mt);
    std::cout<<"Whether any instance of EvCar has Charging type DC : "<<std::boolalpha<<found<<std::endl;
}

void Operation::MapThread(Operation* ptr,Container& data)
{
    if (data.empty())
    {
        throw ExceptionMessage("EMPTY DATAA!!");
    }
    thdata[0]=std::thread(&Operation::AverageGSTOfEvCars, ptr, std::ref(data));
    thdata[1]=std::thread(&Operation::AverageAutomobilePrice, ptr,std::ref(data));
    thdata[2]=std::thread(&Operation::AutomobilesAboveSeatCount4,ptr,std::ref(data));
    thdata[3]=std::thread(&Operation::IfAnyDCType,ptr,std::ref(data));
}

void Operation::JoinThread()
{
    if (thdata.empty())
    {
        throw ExceptionMessage("EMPTY DATAA!!");
    }
    for(auto& itr:thdata){
        if(itr.joinable()){
            itr.join();
        }
    }
}
