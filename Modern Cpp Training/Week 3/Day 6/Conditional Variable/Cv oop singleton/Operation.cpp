#include "Operation.h"

std::shared_ptr<Operation> Operation::m_instance{nullptr};

std::shared_ptr<Operation> Operation::getInstance()
{
        if(m_instance){
            return m_instance;
        }
        m_instance.reset(new Operation());
        return m_instance;
}

void Operation::TakeInput()
{
    std::lock_guard<std::mutex>lk(m_mt);
    std::cin>>m_value;
    if(m_value != 0)
    {
        m_is_input_received= true;
        cv.notify_one();   // Value is produced 
    }
}

void Operation::Square()
{

    std::unique_lock<std::mutex>ul(m_mt);
    //Befor the signal will remain blocked 
    cv.wait(ul , [&](){return m_is_input_received;});
    std::cout<<"Square of "<<m_value<<" is : "<<m_value*m_value<<"\n";

}

int Operation::Factorial(int n)
{   
    if(n<0 ){
        throw std::runtime_error("Negative NUmber!!");
    }
    if(n==0 || n==1){
        return 1;
    }
    else{
        return n*Factorial(n-1);
    }
}

void Operation::operator()()
{

    std::thread t1(&Operation::TakeInput , this);
    std::thread t2(&Operation::Square , this);

    std::future<int>result = std::async(&Operation::Factorial , this , 5);

    t1.join();
    t2.join();
    std::cout<<result.get();
}
