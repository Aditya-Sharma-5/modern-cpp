#include "Employee.h"

Employee::Employee(unsigned int employee_id, std::string employee_name, float employee_salary, EmployeeDepartment employee_department)
: _employee_id{employee_id} , _employee_name{employee_name} , _employee_salary{employee_salary} , _employee_department{employee_department}
{
}
std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_employee_id: " << rhs._employee_id
       << " _employee_name: " << rhs._employee_name
       << " _employee_salary: " << rhs._employee_salary
       << " _employee_department: " <<(int)(rhs._employee_department);
    return os;
}
