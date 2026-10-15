#include "Employee.h"

Employee::Employee(std::string name, std::string id, float salary)
: _name{name} , _id{id} , _salary{salary}
{
}
std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_name: " << rhs._name
       << " _id: " << rhs._id
       << " _salary: " << rhs._salary;
    return os;
}
