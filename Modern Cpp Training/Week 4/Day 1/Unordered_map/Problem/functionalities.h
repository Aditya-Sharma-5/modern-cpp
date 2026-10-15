#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Car.h"
#include<memory>
#include<unordered_map>
#include<future>
#include "EmptyContainerError.h"
#include"InvalidIdError.h"
#include"InvalidInput.h"
#include <cstring>

using CarPointer = std::shared_ptr<Car>;
using DataContainer = std::unordered_map<std::string , CarPointer>;

class functionalities
{
private:
    DataContainer m_car_object;
    static std::shared_ptr<functionalities> m_instance;


    functionalities() = default;

    functionalities(const functionalities&) = default;
    functionalities(functionalities&&) = default;
    
    functionalities& operator&(const functionalities&) = delete;
    functionalities& operator&(functionalities&&) = delete;
public:
    ~functionalities()  = default;

    static std::shared_ptr<functionalities> getInstance();

    void CreateObject();

    CarType FindCarTypeById(std::string& id);

    void DisplayLastNInstance(unsigned int N);

    int CountOfMatchedCarType(CarType car_type);



};

#endif // FUNCTIONALITIES_H
