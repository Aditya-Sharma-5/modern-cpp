#include "Functionalities.h"


void createObject(Container &data)
{
    data.push_back(new FullTimeEmployee("Aadi" , "1A" , 50000.0f , "Embedded Software" , "Pune" , Grade::A , 90));
    data.push_back(new FullTimeEmployee("Kamran" , "2A" , 40000.0f , "Software Developer" , "Banglore" , Grade::A , 85));
    data.push_back(new FullTimeEmployee("Aryan" , "3A" , 30000.0f , "Software Engineer" , "Noida" , Grade::B , 70));
}


void DisplayResultOfCalculateBonus(const Container &data , unsigned int N)
{ 
    // Check Exception if data container is empty or Invalid Data
    if(data.empty())
    {
        throw EmptyContainerError("Data Container is Empty");
    }

    //Check Exception if N is invalid
    if(N > data.size())
    {
        throw InvalidValueError("The Value of N is higher than the size");
    }

    for(int i = 0; i<N ; i++)
    {
        std::cout<<data[i]->CalculateBonus()<<"\n";
    }

}


void DisplayDetailsOfLowestSalary(const Container &data)
{ 
    // Check Exception if data container is empty or Invalid Data
    if(data.empty())
    {
        throw EmptyContainerError("Data Container is Empty");
    }

    float salary = data[0]->salary();
    int check = 0;

    for(int i = 0; i<data.size() ; i++)
    {
        if(data[i] && data[i]->salary() < salary)
        {
            salary = data[i]->salary();
            check = i;
        }
    }

    std::cout<<"Details of Full Time Employee Having Lowest Salary : "<<*data[check]<<"\n";

}



std::vector<std::string> DisplayLocationOfMatchedEmployee(const Container& data , Grade rank)
{ 
    // Check Exception if data container is empty or Invalid Data
    if(data.empty())
    {
        throw EmptyContainerError("Data Container is Empty");
    }

    std::vector<std::string> result ; 

    for(FullTimeEmployee* ptr : data)
    {
        if(ptr->grade() == rank)
        {
            result.push_back(ptr->employeeLocation());
        }
    }

    //Check Exception if N is invalid
    if(result.size() == 0)
    {
        throw InvalidValueError("No Grade match found");
    }

    return result;

}


std::string ProjectNameWhoseIdIsMatched(const Container &data, std::string given_id)
{
    // Check Exception if data container is empty or Invalid Data
    if(data.empty())
    {
        throw EmptyContainerError("Data Container is Empty");
    }

    for(FullTimeEmployee* ptr : data){
        if(ptr && ptr->id() == given_id){
            return ptr->projectName();
        }
    }

    // Exception if Id is not Found
    throw InvalidValueError("Id Not found!!!");

}

void CreateObject(Container &data)
{
}

void DeallocateMemory(Container &data)
{
    // Check Exception if data container is empty or Invalid Data
    if(data.empty())
    {
        throw EmptyContainerError("Data Container is Empty");
    }

    for(FullTimeEmployee* ptr : data)
    {
        if(ptr)
        {
            delete ptr;
        }
    }

}

