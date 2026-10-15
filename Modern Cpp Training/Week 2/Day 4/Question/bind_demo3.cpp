#include<iostream>
#include<vector>
#include<functional>

class Employee
{
private:
    int m_id;
    float m_salary{};
public:
    Employee() = default;
    ~Employee() = default;
    Employee(int id , float salary):m_id{id} , m_salary{salary}{};
    //member function
    void CalculateInsuranceCover(){
        std::cout<<0.2f* m_salary<<"\n";
    }
    void CalculateReturn(){
        std::cout<<0.1f*m_salary<<"\n";
    }

    void CalculatePFAmount(){
        std::cout<<0.05f*m_salary<<"\n";
    }
};
/*
    1) All of these are member function. So object is always required to call them 
    2) To stir them together (for processing) , they need to have same signature -------[void]
    3) To store these in a container . Container needs a type , how to specify type for a function 
*/

// std::function<void()>      --- this not work  , so we tak ehelp form bind
using FnType = std::function<void()>;

void Adaptor(std::vector<FnType>& fns){
    // FOr every function "fn" in the vector "fns" call the function fn
    for(FnType fn:fns){
        fn();
    }
    // e1.CalculateInsuranceCover();
    // e1.CalculateReturn();
    // e1.CalculatePFAmount();
}

int main(){
    Employee e1{101 , 8500.0f};
    auto f1 = std::bind(&Employee::CalculateInsuranceCover , &e1);
    auto f2 = std::bind(&Employee::CalculateReturn , &e1);
    auto f3 = std::bind(&Employee::CalculatePFAmount , &e1);

    std::vector<FnType> fns{f1 , f2 , f3};

    Adaptor(fns);
}