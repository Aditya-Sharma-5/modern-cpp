#include "Operation.h"
std::mutex mt ;

std::shared_ptr<Operation> Operation::m_instance{nullptr};

std::shared_ptr<Operation> Operation::getInstance()
{
    if(m_instance){
        return m_instance;
    }
    m_instance.reset(new Operation());
    return m_instance;
}

void Operation::CreateObject()
{
    m_chasis_instances.push_back(std::make_shared<Chasis>(ChasisType::LADDER , 2.4 , 3.5 , true , true , ChasisMaterial::CARBON_FIBRE));
    m_chasis_instances.push_back(std::make_shared<Chasis>(ChasisType::MONOCOQUE , 2.3 , 3.8 , true , true , ChasisMaterial::ALUMINIUM));
    m_chasis_instances.push_back(std::make_shared<Chasis>(ChasisType::LADDER , 2.4 , 3.4 , true , true , ChasisMaterial::STEEL));
    m_chasis_instances.push_back(std::make_shared<Chasis>(ChasisType::MONOCOQUE , 2.2 , 3.6 , true , true , ChasisMaterial::CARBON_FIBRE));
    m_chasis_instances.push_back(std::make_shared<Chasis>(ChasisType::LADDER , 2.4 , 3.5 , true , true , ChasisMaterial::ALUMINIUM));
}

void Operation::CreateSet()
{
    if(m_chasis_instances.empty()){
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Empty Container!!\n";
        return;
    }
    std::for_each(m_chasis_instances.begin(), m_chasis_instances.end(), 
    [&](Cptr ptr){m_chasis_material_set.emplace(ptr.get()->chasisMaterial());}
    );
}

void Operation::CreatePair()
{
    if(m_chasis_instances.empty()){
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Empty Container!!\n";
        return;
    }

    auto itr = m_chasis_instances.back();

    m_length_width_pair.first = itr->chasisLength();
    m_length_width_pair.second = itr->chasisWidth();
}

void Operation::FIlteredChasis()
{
    if(m_chasis_instances.empty()){
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Empty Container!!\n";
        return;
    }

    std::for_each(m_chasis_instances.begin(), m_chasis_instances.end(),
    [=](Cptr ptr){
        if(m_predicate_function(ptr)){
            m_filtered_chasis_instances.push_back(ptr);
        }
    }
    );

}

void Operation::CreatePriorityQueue()
{
    if(m_chasis_instances.empty()){
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Empty Container!!\n";
        return;
    }

    PQ temp(m_comparator_function);
    for(const Cptr& ptr : m_chasis_instances){
        temp.emplace(ptr);
    }
    m_prioritized_chasis_instances = temp;

    // for(const Cptr & ptr : m_chasis_instances){
    //     m_prioritized_chasis_instances.push(ptr);
    // }
}

void Operation::displayPriorityQueue()
{
    if(m_prioritized_chasis_instances.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Empty Queue!!\n";
        return;
    }

    PQ temp{m_prioritized_chasis_instances};

    std::lock_guard<std::mutex>lk(mt);
    while(!temp.empty()){
        std::cout<<*temp.top();
        temp.pop();
    }

}

void Operation::displayPair()
{
    std::lock_guard<std::mutex>lk(mt);
    std::cout<<"Pair : "<<m_length_width_pair.first<<"      "<<m_length_width_pair.second<<"\n";
}

void Operation::displaySet()
{
    if(m_chasis_material_set.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"empty Set Container!!\n";
        return ; 
    }


    std::lock_guard<std::mutex>lk(mt);
    for(ChasisMaterial c : m_chasis_material_set)
    {
        std::cout<<static_cast<int>(c)<<" ";
    }

}

void Operation::displayFilteredObjects()
{
    if(m_chasis_instances.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Empty Container!!\n";
        return ; 
    }

    std::lock_guard<std::mutex>lk(mt);
    for(Cptr c : m_filtered_chasis_instances){
        std::cout<<c<<"\n\n";
    }

}

void Operation::createThread()
{
    data.emplace_back(&Operation::displayFilteredObjects , this);
    data.emplace_back(&Operation::displayPair , this);
    data.emplace_back(&Operation::displayPriorityQueue , this);
    data.emplace_back(&Operation::displaySet , this);
}

void Operation::JoinThread()
{
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Empty Container!!!\n";
        return ;
    }

    for(std::thread & th : data){
        if(th.joinable()){
            th.join();
        }
    }
}
