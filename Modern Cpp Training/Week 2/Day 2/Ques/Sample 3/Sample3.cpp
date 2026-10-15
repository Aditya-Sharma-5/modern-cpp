
/* 
     1) We declaed a top level function even though it was not used in multiple files/multiple 
        sections of programs 

     2) Now the name "Square" is reserved in this file . The scope of the function Square is not limited so 
        this name cannot be reused! 

     3) We had write "Square" separetely and pass it separetly which makes the program slightly more verbose 
        and difficult to read before you can understand the program 
            - Declare & defination of Square 
            - Passing square function pointer to the adaptor 

     4) It goes against "Functions are also objects" understanding!

            FIRST CLASS FUNCTION [ ALLOWS FUNCTIONS TO RECEIVE SAME TREATMENT AS OBJECTS OF OTHER TYPES]

            A) Every object has a type so I can perform type specific operations 
                - Function also have a type(signature of teh function)

            B) Every object can be passed as a parameter to the function 
                - Function can also be passed as a parametr 
                    --> Type erased function wrapper
                    --> Function Pointers 

            C) Every object can also be returned from a function
                - Function can be returned as a pointer 
                - Function wrapper can be used 

            D) We can copy assign objects to objects of same/similiar types [if this feature is enabled]

                int n1 = 10;
                int n1 = n2 ;    //copy assign

                Vehicle v1;
                Vehicle v2(v1);   //copy constructor
                Vehicle v2 = v1;  //copy assign

            E) We can store objects
                - FUnction can also be stored in container 
                    - conatiner of wrappers or containers of function pointers

*/

/*
    I want to write "logic" which is for one time use , don't want to divide the code into seperate parts
    (define and use at the same time) and I want a proper scope for my function 
            - Lambda function
*/
#include"functionality.h"

//Top Level Function ==> Accessible everywhere
void Square(int num){
    std::cout<<"Square of number : "<<num*num<<"\n";
}

//  [](int number)->void{
//     std::cout<<"Square of number : "<<num*num<<"\n";}

int main(){
    int arr[3] = {10 , 20 , 30};

    //////////////   1st Way
    // Adaptor(
    //     [](int num)->void{
    //     std::cout<<"Square of number : "<<num*num<<"\n";
    //     } ,
    //      arr , 3);

    ////////////     2nd Way
    // Adaptor([](int num){std::cout<<num*num;} , arr , 3);


    ///////    3rd Way 
    auto f1 = [](int num){std::cout<<num*num;};         //f1 is an object 

    f1(5); //25
    Adaptor(f1 , arr , 3);
    return 0 ;
}