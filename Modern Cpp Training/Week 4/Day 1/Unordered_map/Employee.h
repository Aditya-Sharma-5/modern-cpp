#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>

class Employee
{
private:
    unsigned int m_id;
    std::string m_name ; 
    unsigned int m_age ;  
public:
    Employee() = default;
    ~Employee() = default;
    Employee( Employee&&) = delete;
    Employee(const Employee&) = delete;

    Employee(unsigned int id , std::string name , unsigned int age): m_id{id} , m_name{name} , m_age{age}{};

    unsigned int id() const { return m_id; }
    void setId(unsigned int id) { m_id = id; }

    std::string name() const { return m_name; }
    void setName(const std::string &name) { m_name = name; }

    unsigned int age() const { return m_age; }
    void setAge(unsigned int age) { m_age = age; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_name: " << rhs.m_name
           << " m_age: " << rhs.m_age;
        return os;
    }
};

#endif // EMPLOYEE_H
