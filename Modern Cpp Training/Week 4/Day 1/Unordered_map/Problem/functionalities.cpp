#include "functionalities.h"
#include<algorithm>

std::shared_ptr<functionalities> functionalities::m_instance= nullptr;

std::shared_ptr<functionalities> functionalities::getInstance()
{
    if(m_instance)
    {
        return m_instance;
    }
    m_instance.reset(new functionalities());
    return m_instance;
}

void functionalities::CreateObject()
{
    m_car_object.emplace("UP19T9811" , std::make_shared<Car>("UP19T9811" , 25000 , CarType::SEDAN));
    m_car_object.emplace("UP19T9810" , std::make_shared<Car>("UP19T9810" , 85000 , CarType::SPORTS));
    m_car_object.emplace("UP19T9809" , std::make_shared<Car>("UP19T9809" , 55000 , CarType::SPORTS));
}


CarType functionalities::FindCarTypeById(std::string& id)
{
    if(m_car_object.empty())
    {
       throw EmptyContainerError("Data is not available", std::future_errc::no_state); 
    }

    // for(const std::pair<const std::string , CarPointer>& ptr : m_car_object)
    // {
    //     if( strcmp( ptr.second.get()->registrationNumber().c_str() , id.c_str()) )
    //     {
    //         return ptr.second.get()->type();
    //     }
    // }
    auto itr = std::find_if(
        m_car_object.begin(),
        m_car_object.end(),
        [&](const std::pair<const std::string , CarPointer>& ptr){return ptr.second.get()->registrationNumber() == id;}
    );
    if(itr != m_car_object.end()){
        return (*itr).second.get()->type();
    }
    else{
        throw InvalidIdError("Id not FOund" , std::future_errc::no_state);
    }
}

void functionalities::DisplayLastNInstance(unsigned int N)
{

    if(m_car_object.empty())
    {
       throw EmptyContainerError("Data is not available", std::future_errc::no_state); 
    }

    if(N <= 0 || N> m_car_object.size())
    {
        throw InvalidInput("Invalid Value Of N ", std::future_errc::no_state);
    }
    // int count{0};

    // for(const std::pair<const std::string , CarPointer>& ptr: m_car_object)
    // {
    //     if(count++ < m_car_object.size()-N){
    //         continue;
    //     }
    //     std::cout<<*ptr.second<<"\n";
    //     count++;
    // }

    auto itr = m_car_object.begin();
    std::advance(itr , m_car_object.size()-N);

//Advantage , we can use functional programming here 
    std::for_each(
        itr , 
        m_car_object.end(),
        [](const std::pair<const std::string , CarPointer>& ptr){std::cout<<"Key is : "<<ptr.first<<"\n The value are : \n"<<ptr.second<<"\n";}
    );

}


int functionalities::CountOfMatchedCarType(CarType car_type)
{
    if(m_car_object.empty())
    {
       throw EmptyContainerError("Data is not available", std::future_errc::no_state); 
    }

    // int count = 0;

    // for(const std::pair<const std::string , CarPointer>& ptr : m_car_object)
    // {
    //     if(ptr.second.get()->type() == car_type)
    //     {
    //         count++;
    //     }
    // }

    int count = std::count_if(
        m_car_object.begin(),
        m_car_object.end(),
        [&]( const std::pair<const std::string , CarPointer>& ptr){return ptr.second.get()->type() == car_type;}
    );

    if(count){
        return count;
    }
    else
    {
        throw InvalidInput("Invalid Value Of N ", std::future_errc::no_state);
    }

}
