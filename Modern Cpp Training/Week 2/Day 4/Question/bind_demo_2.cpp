#include<iostream>
#include<functional>



/* 
    Type of Function                          : Use of & (YES , NO , BOTH)

    -top-level function(global function )     : Both
    lambda objects as callable                : NO
    Static member finction                    : BOTH
    NON-Static member finction                : Yes
 */
class Employee
{
private:
    int m_id{1};
    static int m_counter ; 
public:

    void CalculateTax(float factor , float salary){
        std::cout<<factor*salary<<"\n";
    }
    
    static void DisplayCounter(int factor){
        std::cout<<m_counter*factor<<"\n";
    }

    Employee() = default;
    ~Employee() = default;
    
};
int Employee::m_counter = 100;
int main(){
    // Example 1 : Hard Code factor
    Employee e1{};
    // we are binding function CalculateTax m in which factor will be 0.1f , and salary will 
    // be the arguement passed by the user 
    auto example_1 = std::bind(&Employee::CalculateTax , &e1 ,0.1f , std::placeholders::_1 );
    example_1(10);

    // note :: JUST LIKE LAMBDA , do  not use & with static member function
    auto example_2 = std::bind(Employee::DisplayCounter , 10);
    example_2();
    return 0 ;

}