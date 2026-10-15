#include<iostream>

/*
    Main FUnction 

    n1
    [ 0000 0000  0000 0000   0000 0000    0000 1010]
    [<-------------4 byte------------------------->]
        0X100H    0X101H       0X102H       0X103H




    Magic Function
    val [alias of received memory location]  ==> Now val is taking 0 memory.



    Symbol Table 
    ------------
    name     type     location     content      alias(Reference)
    n1       int      0X1000H       10             val


*/

/*
    Magic is a function that accepts one integer by "value " and it returns void .
    val in the magic function is same as n1 in the main function.
*/

void Magic(int& val){
    std::cout<<" Address of val in Magic Function "<<&val<<"\n";
    std::cout<<"Val before modification "<<val<<"\n";
    val = -91;
    std::cout<<"Val after modification "<<val<<"\n";

}

int main(){
    int n1 = 10;
    std::cout<<" Address of val in Main Function "<<&n1<<"\n";
    Magic(n1);
    std::cout<<"Magic is done \n";
    std::cout<<"After Magic call n1 has data : "<<n1<<"\n";
    return 0 ;

}