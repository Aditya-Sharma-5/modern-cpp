#include "Operation.h"

Operation* Operation::m_instance = nullptr;


void Operation::CreateObjects()
{
    m_objects.emplace_back(Employee("1A" , 25000.0f , Department::DEVELOPER , 24));
    m_objects.emplace_back(Employee("2A" , 20000.0f , Department::HR , 22));
    m_objects.emplace_back(BussinessOwner("Aadi" , BussinessType::PVT_LTD , "Noida" , 200000.0f));
    m_objects.emplace_back(BussinessOwner("Aryan" , BussinessType::PP , "Mohali" , 170000.0f));

}


std::optional<Container> Operation::ReturnNInstances(unsigned int N, bool m_is_data_required_in_reverse)
{
    if(m_objects.empty())
    {
        return std::nullopt;
    }

    if(N>m_objects.size() || N <=0)
    {
        return std::nullopt;
    }

    Container result;

    if(m_is_data_required_in_reverse)
    {
        auto itr = m_objects.rbegin();
        int cnt = 0;
        for(int i = 0 ; i<N;i++)
        {
            result.emplace_back(*itr++);
        }
    }

    else
    {
        auto itr = m_objects.begin();
        int cnt = 0;
        for(int i = 0 ; i<N;i++)
        {
            result.emplace_back(*itr++);
        }
    }
    return result;
}






void Operation::DisplayCalculateTaxAmount()
{
    if(m_objects.empty()){
        std::cerr<<"Empty Data Container\n";
    }

}

std::optional<std::string> Operation::ReturnEmployeeId()
{
    if(m_objects.empty()){
        std::cerr<<"Empty Data Container\n";
    }
    for(const Vr & v : m_objects){
        if(std::holds_alternative<Employee>(v)){
            float max_salary = std::get<0>(v).salary();
            std::string max_salary_employee_id = std::get<0>(v).id();
            
        }
    }
    
    return std::optional<std::string>();
}

std::optional<bool> Operation::CheckCalculatePFIsAbove5000()
{
    if(m_objects.empty()){
        return std::nullopt;
    }

    bool m_is_employee_found{false};

    for(const Vr& v : m_objects ){
        if(std::holds_alternative<Employee>(v)){
            m_is_employee_found = true ;

            Employee emp = std::get<0>(v);

            if(emp.CalculatePf()<=5000){
                return false;
            }
        }
    }
    if(!m_is_employee_found){
        return std::nullopt;
    }

    return true;
}




Operation *Operation::GetInstance()
{
    if(m_instance){
        return m_instance;
    }
    m_instance = new Operation();
    return m_instance;
}
