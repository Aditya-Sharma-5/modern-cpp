#include<iostream>

/*
    Main FUnction 

    n1
    [ 0000 0000  0000 0000   0000 0000    0000 1010]
    [<-------------4 byte------------------------->]
        0X100H    0X101H       0X102H       0X103H




    Magic Function
    val
    [ 0000 0000  0000 0000   0000 0000    0000 1010]
    [<-------------4 byte------------------------->]
        0X080H    0X081H       0X082H       0X083H

*/

/*
    Magic is a function that accepts one integer by "value " and it returns void .
*/

void Magic(int val){
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