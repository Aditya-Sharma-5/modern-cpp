//If Initializer 

/*
    Pass anumber to IsEven and return true or false (check for even )
    If number is even , client should print its square , else print number's cube

    At the end of the step 1 , print the factorial of the guven number 

*/

#include<iostream>
#include<list>

bool IsEven(int n){
    return n%2==0;
}

int Factorial(int num){
    if(num<0){
        throw std::logic_error("Logically , Factorials are not calculated for negative numbers!!\n");
    }
    if(num == 0|| num ==1 ){
        return 1; 
    }
    else {
        return num*Factorial(num-1);
    }
}

std::list<int> NumberGenerator(){
    return std::list<int>{1 , 2, 3, 4,5};
}

/*
int main(){
    int num = 10; 
    bool ans = IsEven(num);

    // Part 1
    if(ans){
        std::cout<<"Square of number : "<<num*num<<"\n";   
    }
    else{
        std::cout<<"Cube of number : "<<num*num*num<<"\n";
    }
    // Part 2
    int fact_ans = Factorial(num);
    std::cout<<fact_ans<<"\n";

    return 0 ;
}
*/

//This will reduce the ans bool variable
int main(){
    int num = 11; 

    // Part 1
    if(bool ans = IsEven(num); ans){
        std::cout<<"Square of number : "<<num*num<<"\n";   
    }
    else{
        std::cout<<"Cube of number : "<<num*num*num<<"\n";
    }
    // Part 2
    int fact_ans = Factorial(num);
    std::cout<<"Factorial of the number : " <<fact_ans<<"\n";

    //Part 3
    if(std::list<int>data = NumberGenerator() ; data.size()>3){
        for(int val : data){
            std::cout<<val<<" ";
        }
    }
    else{
        std::cout<<"The size is less than 3\n";
    }

    return 0 ;
}