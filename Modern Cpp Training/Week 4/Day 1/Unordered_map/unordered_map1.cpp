#include<unordered_map>
#include"Employee.h"
#include<memory>

using EmployeePtr = std::shared_ptr<Employee>;

int main(){
    std::unordered_map<unsigned int , EmployeePtr> data{
        // Here we copied 108 , and shared pointer [we use copy constructor of share pointer , not Employee]
        {108 , std::make_shared<Employee>(108 , "Aadi" , 22)}
    };

    data.emplace(109 , new Employee(109 , "Hemant" , 22));
    /*
        std::pair<unsigned int , shared_ptr<Employee>
        Here the raw pointer can be implicitely converts it into the shared pointer class
    */


    // When we use emplace , i check the type of the container first , then 2nd thing is 
    // all the thing are provided into the arguements are of the same type required by the map arguements 

    //STep 3 , then it perfect-forwarding the data into the pair constructor ---> so that memory 
            // is constructed into the map .  
}