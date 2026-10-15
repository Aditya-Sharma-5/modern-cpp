#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<vector>
#include"Employee.h"

using DataContainer = std::vector<Employee*>;

/*
    Takes an empty container , Creates instances on heap and store 
    their pointer in the container received.
*/
void createObjects(DataContainer& data);

void deleteObject(DataContainer& data);

/*

*/
float averageSalary(const DataContainer& data);


Department FindDepartmentById(const DataContainer& data , const std::string id );

bool IsDataContaiinerAbove5YExperience(const DataContainer& data);




std::string* SkillsetForMaxSalariedEmployee(const DataContainer& data);

void showObjects(const DataContainer& data);


#endif // FUNCTIONALITIES_H
