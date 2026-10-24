#include<iostream>
#include<functional>

/*
    std::bind

    mv source destination

    cp source destination

*/

    /*
        UTC : UK Government Traffic Control

        50 commands like -
            - command-name(id_of_equipment , new_state , duration , upcoming state)

        After Changing it - 
            - command-name(idof-equipment , new_state , upcoming_state , duration)

        solution - we give you a interface(a way to access something) where you can pass parameters in the 
                    old sequence and my system accepts it in the new sequence

                .... std::bind
    */




void formula(int x , int y , int z){
    std::cout<<(x+y) -z<<"\n";
}

/*
    member function 
        a) non-static function : object is required to call the function
        b) static function
*/
int main(){
    formula(10 , 20 , 30);

    /*
        Use case 1) : I want to pass parameters in a new order
                    z , y , x

                    whatever parameters user passes to the function
    */

    auto binded_formula = std::bind(&formula , std::placeholders::_3 , std::placeholders::_2 , std::placeholders::_1);
    binded_formula(10 , 20 , 30);



  //////////////Scenario 2 : 
    // swap number & parameters
    //Note : lambda is not a function . It is an object of a class . & operator is not overloaded for it .
    //       DO NOT USE & WITH LAMBDA FUNCTION
    auto f1 = [](int num , int factor){std::cout<<num/factor<<"\n";};

    auto binded_f1 = std::bind(f1, std::placeholders::_2 , std::placeholders::_1);

    binded_f1(4 , 10);   // f1(10 , 4);




    /////////////// Scenario 3 - parameters by reference

    // if you are working in by reference in bind -- use std::ref with lvalues always
    auto f2 = [](int& num , int& factor){num = 20 ; factor = 20;};
    int p = 10 , q = 20 ;
    auto binded_f2 = std::bind(f2 , std::ref(p) , std::ref(q));


    //////////// use case : hard-code or fix-value for some parameters 
            //    ex ;  Call forrmula function where x is always taken as 100
        auto example_1 = std::bind(&formula , 100 , std::placeholders::_2 , std::placeholders::_1);

        example_1(10 , 20);   // formula(100 , 20 , 10);


}

/* 
    Scenario 1) : binding top level function parameters (by value)
    Scenario 2) : Binding a lambda object parameters (by value).
    Scenario 3) : Binding callable where some/all parameters are accepted by reference .
    Scenario 4) : Binding non - static member function  .
    Scenario 5) : Binding static member function  .
    Scenario 6) : using bind to create new callables to meet requirements.

    Application of bind : 
                    a) swap parameters of a function 
                    b)Assign a fixed , hard-coded value to a function parameter so that it is no
                      longer accepted a function call  
                    c) Create modified callables where objects pointers are pre-attached to member function/callable
*/