/*
    std::make_pair
    std::make_unique
    std::make_share

    It allows a function /relay received parameters in their original form 
    (lvalues will be forwarded , rvalues will be forwarded as lvalue)
*/

#include<iostream>

void Magic(int& n1 , std::string& name , float && salary , const std::string* skills){
}

//n1 from main will be copied into the scope of MiddleFunction 
//a new variable will be created in the scope of MiddleFunction

//name string is also copied and a new variable is created in the MiddleFunction

// s is also a new variable (copy of salary from main function)

//sk is a copy of the address of the first element of skills array


// void MiddleFunction(int n1 , std::string name , float s , std::string* sk){
//     // std::string n = name;
//     // Magic(n1 , n , std::move(s) , sk );      // used when the name in the parameter is used as std::string name 
//     Magic(n1 , name , std::move(s) , sk);
// }



/*
    Middle Function / Relay Function / Forwarding FUnction : Accept parameters 
*/
template<typename... T>
void MiddleFunction(T&&... args){
    Magic(std::forward<T>(args)...);
}


int main(){
    int n1 = 10; //non-const integer type lvalue
    std::string name = "Aditya"; //non-const std::string type lvalue
    float salary = 1100.0f; //non-const float type lvalue
    std::string skills[2] = {"Coding" , "Training"}; //skills is a non-const pointer pointing to an array of 2 non-const std::string values

    //MiddleFUnction ---------> Magic()

    MiddleFunction(n1 , name , salary , skills);
}
/*
        Perfect Forwarding Table 

        A function which is templated , involves type deduction can be a relay function if 
        its parameters are received T&& args where T is the deduced type

        Note : In regular function with no type deduction , && means Rvalue reference 
        void Mah=gic(int&& val)-------> val accepted as Rvalue reference 

        In templated function involving type deduction , && means forward reference 
        (Unofficial means : Universal reference)

        template<typename...T>
        void Magic(A&&... args){
            //forward parameters here 
        }
*/