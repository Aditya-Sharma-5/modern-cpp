#include "Employee.h"

Employee::Employee(std::string id, float salary, Department department, unsigned int age)
: m_id{id} , m_salary{salary} , m_department{department} , m_age{age}
{
}
float Employee::CalculatePf() const
{
    if(m_department == Department::DEVELOPER){
        return (0.2*m_salary);
    }
    return (0.1*m_salary);
}
std::ostream &operator<<(std::ostream &os, const Employee &rhs)
{
    os << "m_id: " << rhs.m_id
       << " m_salary: " << rhs.m_salary
       << " m_department: " <<static_cast<int>( rhs.m_department)
       << " m_age: " << rhs.m_age;
    return os;
}
