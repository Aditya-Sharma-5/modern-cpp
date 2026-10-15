#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include"EmployeeDepartment.h"
class Employee
{
private:
    unsigned int _employee_id{1};
    std::string _employee_name{""};
    float _employee_salary{10000.0f};
    EmployeeDepartment _employee_department{EmployeeDepartment::FLM};

public:
    Employee() = default;
    ~Employee() = default;

    Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = delete;

    Employee( Employee&&) = delete;
    Employee& operator=( Employee&&) = delete;

    Employee(unsigned int employee_id , std::string employee_name , float employee_salary , EmployeeDepartment employee_department);

    unsigned int employeeId() const { return _employee_id; }
    void setEmployeeId(unsigned int employee_id) { _employee_id = employee_id; }

    std::string employeeName() const { return _employee_name; }
    void setEmployeeName(const std::string &employee_name) { _employee_name = employee_name; }

    float employeeSalary() const { return _employee_salary; }
    void setEmployeeSalary(float employee_salary) { _employee_salary = employee_salary; }

    EmployeeDepartment employeeDepartment() const { return _employee_department; }
    void setEmployeeDepartment(const EmployeeDepartment &employee_department) { _employee_department = employee_department; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
