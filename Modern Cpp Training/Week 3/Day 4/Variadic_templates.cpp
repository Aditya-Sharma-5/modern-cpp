/*  
    Templates : 
            Write algorithms which are type agnostic! [not specific to a type]

    Recursion : 
            So;ve problem by dividing them into smaller versions of similiar problems

    Variadic Templates : TEMPLATES + RECURSION
    [NOT GOOD , HORRIBLE SYNTAX]
    [Shuri : IF IT WORKS , DOESN'T MEAN THAT IT CAN NOT BE IMPROVED]

*/  
#include<iostream>
/*
    Binary + Operator
*/

template<typename T>
T PlusOperation(T arg){
    return arg;
}

/*
    PlusOperation takes 2 parameters 
    
    FIrst parameter named as n1 
    All other parameters are collected together in some container in the backend . This container is of 
    type REMAINING

    ... represent the ellipsis operator
*/

template<typename T , typename... Remaining>   // more than 1 template parameters called 
T PlusOperation(T n1 , Remaining... args){     //function takes 1 parameter n1 , and more than 1 parameter 
                                               // called args [all of the same type remaining]
    
    return ( n1 + PlusOperation(args...));     // PlusOperation takes all arguements from args to everything 
                                               // on the right 
}


int main(){

    //                            n1                  Remaining --[COntainer]
    std::cout<<PlusOperation<int>(10 ,             20 , 40 , 50)<<"\n";



    std::cout<<PlusOperation<float>(10.1 , 20.34 , 50.33)<<"\n";
    std::cout<<PlusOperation<int>(10 , 20 , 40 )<<"\n";
    std::cout<<PlusOperation<int>( 40 , 50)<<"\n";
}