#include "FullTimeEmployee.h"

FullTimeEmployee::FullTimeEmployee(std::string name, std::string id, float salary, std::string project_name, std::string employee_location, Grade grade  , unsigned int bonus_percent)
: Employee(name , id , salary)
{
    _project_name = project_name;
    _employee_location = employee_location;
    _grade = grade;
    _bonus_percent = bonus_percent;

}

float FullTimeEmployee::CalculateBonus()
{
    if(_grade == Grade::A){
        return (_bonus_percent * salary());
    }

    else if(_grade == Grade::B){
        return (_bonus_percent * (0.5*salary()));
    }
    else{
        return (_bonus_percent* (0.25 * salary()));
    }
}


std::ostream &operator<<(std::ostream &os, const FullTimeEmployee &rhs) {
    os << static_cast<const Employee &>(rhs)
       << " _project_name: " << rhs._project_name
       << " _employee_location: " << rhs._employee_location
       << " _grade: " <<static_cast<int>(rhs._grade)
       << " _bonus_percent: " << rhs._bonus_percent;
    return os;
}
