#include<iostream>
#include<list>
#include<array>

/* 
    We want to create a function where 
    either an array of integers or a  list of integers will be passed 

    POSSIBLY , INFINITE TYPES OF CONAINERS CAN BE PASSED AS LONG AS ELEMENTS ARE OF TYPE INT

    The function must support iterators!

*/

template<typename Container>
void Display(Container& data){
    for(int val : data){
        std::cout<<val<<" ";
    }
}

int main(){
    std::list<int> data1{12, 222, 31, 12, 32};
    std::array<int , 4>data2 {22, 12, 32, 322};

    

    Display(data1);
    std::cout<<"\n";
    Display(data2);

    // This is also used here
    // Display<std::list<int>>(data1);
    // Display<std::array<int , 4>>(data2);
    return 0 ;
}