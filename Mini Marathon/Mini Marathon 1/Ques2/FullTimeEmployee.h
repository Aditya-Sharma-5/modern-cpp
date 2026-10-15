#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H

#include"Employee.h"
#include"Grade.h"
#include <ostream>

class FullTimeEmployee : public Employee
{
private:
    std::string _project_name{""};
    std::string _employee_location{""};
    Grade _grade{Grade::A};
    unsigned int _bonus_percent{1};

public:    
    FullTimeEmployee() = default;    //Default Constructor
    ~FullTimeEmployee() = default;   //Default Destructor

    FullTimeEmployee(const FullTimeEmployee&) = delete;   //Copy Constructor Disable
    FullTimeEmployee(FullTimeEmployee&&) = delete;        //Move Constructor Disable

    FullTimeEmployee& operator=(const FullTimeEmployee&) = delete;     //Copy Assignment Operator Disable
    FullTimeEmployee& operator=(FullTimeEmployee&&) = delete;          //Copy Assignment Operator Disable

    // Parametrized Constructor
    FullTimeEmployee(std::string name , std::string id , float salary , std::string project_name , std::string employee_location , Grade grade , unsigned int bonus_percent);

    // Overriding the CalculateBonus Function
    float CalculateBonus() override;


    // Required Getter and Setter Function 
    std::string projectName() const { return _project_name; }

    std::string employeeLocation() const { return _employee_location; }

    Grade grade() const { return _grade; }

    unsigned int bonusPercent() const { return _bonus_percent; }
    void setBonusPercent(unsigned int bonus_percent) { _bonus_percent = bonus_percent; }

    friend std::ostream &operator<<(std::ostream &os, const FullTimeEmployee &rhs);



};

#endif // FULLTIMEEMPLOYEE_H
