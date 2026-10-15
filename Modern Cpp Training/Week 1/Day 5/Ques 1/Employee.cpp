#include"Employee.h"
std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_employee_id: " << rhs._employee_id<<"\n"
       << " _employee_name: " << rhs._employee_name<<"\n"
       << " _employee_department: ";

        if(static_cast<int>(rhs._employee_department) == 1){
            os<<"DEVELOPER\n";
        }
        else if(static_cast<int>(rhs._employee_department) == 2){
            os<<"HR\n";
        }
        else{
            os<<"MARKETING\n";
        }

      os<< " _employee_salary: " << rhs._employee_salary<<"\n"
       << " _employee_location: " << rhs._employee_location<<"\n"
       << " _employee_experience: " << rhs._employee_experience<<"\n"
       << " _employee_age: " << rhs._employee_age<<"\n"
       << " _employee_skillset: ";

       for(int i = 0;i<3;i++){
        os<<rhs._employee_skillset[i]<<" ";
       }
    return os;
}

Employee::Employee(std::string employee_id, std::string employee_name, Department employee_department, float employee_salary, std::string employee_location, float employee_experience, std::string employee_age, std::string* employee_skillset)
:_employee_id{employee_id} , _employee_name{employee_name} , _employee_department{employee_department} , _employee_salary{employee_salary} , _employee_location{employee_location} , _employee_experience{employee_experience} , _employee_age{employee_age} , _employee_skillset{employee_skillset}
{
}

Employee::Employee(std::string employee_id, std::string employee_name, std::string employee_location)
:_employee_id{employee_id} , _employee_name{employee_name} ,_employee_location{employee_location}
{
}

float Employee::operator+(const Employee &obj)
{

    return (_employee_experience + obj._employee_experience);
}
