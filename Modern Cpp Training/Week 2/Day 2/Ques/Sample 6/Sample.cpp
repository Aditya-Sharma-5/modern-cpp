#include<iostream>
#include<functional>

/*
    User passes one string by value reference 
    one function which can accept string by lvalue reference and return char
    Display output based on function passed
*/

// void Magic(std::string& data_member , std::function<char(std::string&)> fn){


// }
// int main(){
//     std::string name = "harshit"

//     Magic(name , [](std::string& name){})
// }



/*
    if you create a lambda function inside the scope of a function X , any data value which is local
    to X , referenced to X , passed to X [available for access in X ] can be "CAPTURED" without 
    passing it to the lambda.
*/

int main(){
    int n1 = 10 ; 

    /*
        [ ] --> are use to capture data from "enclosing" function of the lambda for use 
                inside the cope of lambda

    */

   auto f1 = [n1](){std::cout<<n1*10;};
   f1();
}