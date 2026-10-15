#include"Operation.h"

Operation* Operation::m_object= nullptr;

void Operation::withdraw()
{
    for(unsigned int i = 0; i<100 ; i++){
        std::lock_guard<std::mutex>lb(_mutex);
        _amount-=10;
    }
}

void Operation::deposit()
{
    for(unsigned int i = 0; i<100 ; i++){
        std::lock_guard<std::mutex>lb(_mutex);
        _amount+=10;
    }
}
Operation::Operation(int amt){
    _amount = amt;
}

void Operation::createThreads()
{
    // auto itr = m_thread.begin();
    m_thread.emplace_back(std::thread(&Operation::withdraw , m_object));
    m_thread.emplace_back(std::thread(&Operation::deposit , m_object));
}

void Operation::joinThreads()
{
    for(std::thread& th : m_thread){
        if(th.joinable()){
            th.join();
        }
    }
}

void Operation::Display()
{
    std::cout<<"Final Amount : "<<_amount<<"\n";
}

void Operation::operator()()
{
    m_object = Operation::CreateObjects(1000);
    m_object->createThreads();
    m_object->joinThreads();
    m_object->Display();
}

Operation *Operation::CreateObjects(int amt)
{
    //If m_object is not null , it indicates that object was already initialized once . We can 
    // reuse the same object.
    if(m_object){
        return m_object;
    }
        m_object = new Operation(amt);
        return m_object;
    // return nullptr;
}
