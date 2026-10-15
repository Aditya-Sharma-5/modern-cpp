#include "Functionalities.h"

void createObjects(DataContainer &data)
{
    std::string* sk = new std::string[3];
    sk[0] = "Coding";
    sk[1] = "Web D";
    sk[2] = "Python";
    // data.push_back(new Employee("1a" , "Aadi" , Department::DEVELOPER, 11000.5,"Pune" , 5.5 , "23" , ["Devloper" , "UI" , "CPP"]));
    data.push_back(new Employee("1a" , "Aadi" , Department::DEVELOPER , 19850 , "Pune " , 5.5 , "21" , sk));
    std::string* sk1 = new std::string[3];


    //  data.push_back(new Employee())



  

    sk1[0] = "Communication";
    sk1[1] = "Email Ettiquete";
    sk1[2] = "HR";
    data.push_back(new Employee("1b" , "Aryan" , Department::HR , 19850 , "Bangalore" , 6.5 , "23" , sk1));
    std::string* sk2 = new std::string[3];
    sk2[0] = "English";
    sk2[1] = "Email Ettiquete";
    sk2[2] = "Communication";
    data.push_back(new Employee("1c" , "Vipin" , Department::MARKETING , 19850 , "Noida" , 3.5 , "21" , sk2));
}


float averageSalary(const DataContainer &data)
{
    if(data.empty()){
        throw std::runtime_error("Exception because of empty container \n");
    }

    float total {0.0f};
    std::size_t cnt = 0;

    for(Employee* ptr : data){
        if(ptr){
            total += ptr->employeeSalary();
            cnt++;
        }
    }

    return (total/cnt);
}

Department FindDepartmentById(const DataContainer &data, const std::string id)
{
    if(data.empty()){
        throw std::runtime_error("Exception because of empty container \n");
    }

    for(Employee* ptr : data){
        if(ptr && ptr->employeeId() == id){
            return ptr->employeeDepartment();
        }
    }

    throw std::runtime_error("Id not found");
}

bool IsDataContaiinerAbove5YExperience(const DataContainer &data)
{
    if(data.empty()){
        throw std::runtime_error("Exception because of empty container \n");
    }

    for(Employee* ptr : data){
        if(ptr && ptr->employeeExperience()<= 5.0){
            return false;
        }
    }

    return true;
}

void deleteObject(DataContainer &data)
{
    for(Employee* ptr : data)
    {
        if(ptr)
        {
            if(ptr->employeeSkillset()){
                delete[] (ptr->employeeSkillset());
            }
            delete ptr;
        }
    }
}

std::string *SkillsetForMaxSalariedEmployee(const DataContainer &data)
{
    if(data.empty()){
        throw std::runtime_error("Exception because of empty container \n");
    }

    float maxSal = data[0]->employeeSalary();
    std::string* max_sal_skillset = data[0]->employeeSkillset();

    for(Employee* ptr : data){
        if(ptr && ptr->employeeSalary()>maxSal){
            maxSal = ptr->employeeSalary();
            max_sal_skillset = ptr->employeeSkillset();
        }
    }

    return max_sal_skillset;
}

void showObjects(const DataContainer &data)
{
    if(data.empty()){
        throw std::runtime_error("Exception because of empty container \n");
    }
    for(Employee* ptr: data){
        std::cout<<(*ptr)<<"\n\n";
    }
}
