#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include"Department.h"

class Employee
{
private:
    std::string m_id{"1A"};
    float m_salary{0.0f};
    Department m_department{Department::DEVELOPER};
    unsigned int m_age{22} ;

public:
    Employee() = default;
    ~Employee() = default;

    Employee(const Employee&) = default;
    Employee(Employee&&) = default;

    Employee& operator=(const Employee&) = delete;
    Employee& operator=(Employee&&) = default;

    Employee(std::string id , float salary , Department department , unsigned int age);

    float CalculatePf() const ;

    std::string id() const { return m_id; }
    void setId(const std::string &id) { m_id = id; }

    float salary() const { return m_salary; }
    void setSalary(float salary) { m_salary = salary; }

    Department department() const { return m_department; }
    void setDepartment(const Department &department) { m_department = department; }

    unsigned int age() const { return m_age; }
    void setAge(unsigned int age) { m_age = age; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
