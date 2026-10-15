#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include"Department.h"
class Employee
{
private:
    std::string _employee_id{""};
    std::string _employee_name{""};
    Department _employee_department{Department::DEVELOPER};
    float _employee_salary{10000.0f};
    std::string _employee_location{""};
    float _employee_experience{1.0f};
    std::string _employee_age{"21"};
    std::string* _employee_skillset{nullptr};
public:
    Employee() = delete;
    ~Employee() = default;
    Employee(const Employee&) = delete;
    Employee(Employee&&) = delete;
    Employee& operator=(const Employee&)= delete;
    Employee& operator=( Employee&&)= delete;

    Employee(std::string employee_id , std::string employee_name , Department employee_department , float employee_salary , std::string employee_location , float employee_experience , std::string employee_age , std::string* employee_skillset);
    Employee(std::string employee_id , std::string employee_name , std::string employee_location);

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);

    float operator+(const Employee& obj);

    std::string employeeId() const { return _employee_id; }

    std::string employeeName() const { return _employee_name; }

    Department employeeDepartment() const { return _employee_department; }

    float employeeSalary() const { return _employee_salary; }

    std::string employeeLocation() const { return _employee_location; }

    float employeeExperience() const { return _employee_experience; }

    std::string employeeAge() const { return _employee_age; }

    std::string* employeeSkillset() const { return _employee_skillset; }
};
#endif // EMPLOYEE_H
