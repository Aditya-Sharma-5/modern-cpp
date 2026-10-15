#include<iostream>

int main(){

    int n1 = 10;
    std::string name = "AADI";


    auto f1 = [ ](){std::cout<<"HII";};    //NO CAPTURE

    auto f2 = [n1](){std::cout<<n1<<"\n";};


    /*
    n1 & name are captured by value (n1 and name will)
    */
    auto f3 = [n1 , name](){std::cout<<n1<<" "<<name<<"\n";};


    /*
        n1 will not be modifyable by default if it is captured by value.
        To do so , use mutable kryword.
    */
    // auto f4 = [n1](){n1 = 4;};        // this gives you error
    auto f4 = [n1]() mutable{n1 = 8;};
    // auto f4 = [&n1](){n1 = 7;};      // or you can do this also 


    /*
        using = operator f5 capture all the variables of main function by valye
        NOTE : if you want to change the value , must use MUTABLE ,, 
        --------------because if you capture by value , it act as a constant [in lambda function]
    */
    auto f5 = [=](){std::cout<<n1<<" "<<name<<"\n";};


    /*
        All surrounding variables are captured by reference
    */
    auto f6 = [&](){n1 = 10;};


    /*
        name by value , n1 by reference
                Hence , we can change n1 , but not name 
    */
    auto f7 = [&n1 , name](){n1 = 33 ; std::cout<<n1<<" "<<name<<"\n";};
}