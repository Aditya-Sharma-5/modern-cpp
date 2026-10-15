// #include "Functionalities.h"
#include <thread>
#include <iostream>
#include <future>
#include "DataHandler.h"
int main()
{
    UniquePointer &ptr = DataHandler::_getinstance();
    Container data;
    EngineContainer data1;
    ptr->CreateObjects(data1, data);
    // CreateObjects(data1, data);
    //  Display(data);

    // std::future<std::optional<RefContainer>> result = std::async(&ReturnTillN, std::ref(data1), 2);
    std::future<std::optional<RefContainer>> result = std::async(&DataHandler::ReturnTillN, ptr.get(), std::ref(data1), 2);
    std::future<bool> BoolAns = std::async(&DataHandler::AllEngineTorqueOver120, ptr.get(), std::ref(data));
    std::future<RefContainer> ans = std::async(&DataHandler::HighestEngineTorque, ptr.get(), std::ref(data));
    std::future<EngineType> ansss = std::async(&DataHandler::FindEngineTypeBasedOnID, ptr.get(), std::ref(data), "MH-123");
    std::future<float> Answer = std::async(&DataHandler::FindAverageHorsePower, ptr.get(), std::ref(data));

    std::cout << "*************************Reference Conatiner of Engine till N************************" << std::endl;
    std::optional<RefContainer> resultt = result.get();
    RefContainer resulttt;
    if (resultt.has_value())
    {
        resulttt = resultt.value();
    }
    for (auto &ptr : resulttt)
    {
        std::cout << ptr << std::endl;
    }

    std::cout << "*************************************************" << std::endl;
    bool b = BoolAns.get();
    if (b == 1)
    {
        std::cout << "All instance of Engine Torque is having power above 120" << std::endl;
    }
    else
    {
        std::cout << "All instances doesnt have Engine Torque over 120 " << std::endl;
    }
    std::cout << "*************************************************" << std::endl;

    std::cout << "***********************Highest Torque*****************************88" << std::endl;

    RefContainer ans2 = ans.get();
    for (auto ptr : ans2)
    {

        std::cout << ptr << std::endl;
    }

    std::cout << "***********************Average HorsePower****************************** - " << std::endl;

    float Answer2 = Answer.get();
    std::cout << "The Average of hoursepower will be " << Answer2 << std::endl;

    std::cout << "*********************************************************************************************************" << std::endl;

    EngineType a = ansss.get();
    if (a == EngineType::CRDI)
    {
        std::cout << "CRDI" << std::endl;
    }

    if (a == EngineType::MPFI)
    {
        std::cout << "EngineType based on the ID MPFI" << std::endl;
    }
    if (a == EngineType::TURBOCHARGED)
    {
        std::cout << "TURBOCHARGED" << std::endl;
    }

    return 0;
}