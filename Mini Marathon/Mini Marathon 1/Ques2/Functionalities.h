#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"FullTimeEmployee.h"
#include"EmptyContainerError.h"
#include"InvalidValueError.h"
#include<vector>

using Container = std::vector<FullTimeEmployee*>;

/*
    Input Arguement : This function takes an empty Container
    Expected Output : Filled container of objects of Full Time Employee
    Return Type : Void 
*/
void createObject(Container& data);

/*
    Input Arguement : This function takes a filled Container and an unsigned int for first N instances
    Expected Output : Display the result of Calculate bonus for first N instances
    Return Type : Void 
*/
void DisplayResultOfCalculateBonus(const Container& data , unsigned int N);


/*
    Input Arguement : This function takes a filled Container
    Expected Output : Display the details of the intance having lowest salary 
    Return Type : Void 
*/
void DisplayDetailsOfLowestSalary(const Container& data);


/*
    Input Arguement : This function takes a filled Container and a rank of type Grade
    Expected Output : Display the Location of the EMployee WHose rank is matched 
    Return Type : Container of String Type
*/
std::vector<std::string> DisplayLocationOfMatchedEmployee(const Container& data , Grade rank);

/*
    Input Arguement : This function takes a filled Container and a string id 
    Expected Output : Returns the project name of the employee whose id is matched 
    Return Type : String
*/
std::string ProjectNameWhoseIdIsMatched(const Container& data , std::string given_id);


/*
    Input Arguement : This function takes a filled Container
    Expected Output : Deallocate the memory on heap
    Return Type : Void 
*/
void DeallocateMemory(Container& data);


#endif // FUNCTIONALITIES_H
