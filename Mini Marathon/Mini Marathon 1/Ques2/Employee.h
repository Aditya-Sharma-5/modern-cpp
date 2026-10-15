#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>

class Employee
{
private:

    // Data Members
    std::string _name{""};
    std::string _id{""};
    float _salary{0.0f};

    // Pure Virtual Function
    virtual float CalculateBonus() = 0;
public:    
    Employee() = default;    //Default Constructor
    ~Employee() = default;   //Default Destructor

    Employee(const Employee&) = delete;   //Copy Constructor Disable
    Employee(Employee&&) = delete;        //Move Constructor Disable

    Employee& operator=(const Employee&) = delete;     //Copy Assignment Operator Disable
    Employee& operator=(Employee&&) = delete;          //Copy Assignment Operator Disable

    // Parametrized Constructor  
    Employee(std::string name , std::string id , float salary);

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    float salary() const { return _salary; }
    void setSalary(float salary) { _salary = salary; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);

};

#endif // EMPLOYEE_H
