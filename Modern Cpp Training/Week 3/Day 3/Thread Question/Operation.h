#ifndef OPERATION_H
#define OPERATION_H

#include<list>
#include<variant>
#include<optional>
#include"Employee.h"
#include"BussinessOwner.h"

using Vr = std::variant<Employee , BussinessOwner>;
using Container = std::list<Vr>;

class Operation
{
private:
    Container m_objects{};
    Operation() = default;
    ~Operation() = default;

    Operation(const Operation&) = delete;
    Operation(Operation&&) = delete;

    Operation& operator=(const Operation&) = delete;
    Operation& operator=(Operation&&) = delete;

    static Operation* m_instance;


public:

    // if()
    /*
        This function cretaes 2-2 objects each of Employee & Bussiness Class 
        Expected Output : m_objects must get populated with the objects of Employee & Bussiness Class 
        Return Type : Void 
    */
    void CreateObjects();

    /*
        This function returns either first or Last N instances based on the boolean value passed 
        Expected Output : An OPtional Data Container may get instantiated with either valid variants or std::nullOpt
        Return Type : std::optional<Container>
    */

    std::optional<Container> ReturnNInstances(unsigned int N , bool m_is_data_required_in_reverse);


    /*
        This function returns the string based Id of the employee have highest salary 
        Expected Output : An optional with the string or nullopt
        Return Type : std::optional<std::string>
    */
    std::optional<std::string> ReturnEmployeeId();

    /*
        This function must show the outputs of CalculateTaxAmount function
        Expected Output : Console should display relevant string msges and output
        Return Tyope : Void 
    */
    void DisplayCalculateTaxAmount();


    /* 
        This functions returns true if all Employees have CalculatePf amount is above 5000 
    */
    std::optional<bool> CheckCalculatePFIsAbove5000();


    static Operation* GetInstance();

};

#endif // OPERATION_H
