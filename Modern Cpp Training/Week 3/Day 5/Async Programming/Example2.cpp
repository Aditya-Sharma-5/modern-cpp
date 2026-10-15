#include<iostream>
#include<future>

int takeInput(){

    int num{-1};
    std::cin>>num;
    return num;
}


// Fact takes one parameter - a number which will arrive in future (after function has started execution)
int fact(std::future<int>& ft){

    std::cout<<"Function execution start\n";

    int num = ft.get();   // We cannot proceed from this line before pr.set_value();
    if(num<0){
        throw std::runtime_error{"Negative Number"};
    }
    if(num == 0 || num ==1){
        return 1 ;
    }
    int ans = 1; 
    for(int i = 2; i<=num ; i++){
        ans *=i;
    }
    
    return  ans ;
}

int SumOfArray(int* arr , int size){
    int total{0};
    for(int i  =0; i<size;i++){
        total += arr[i];
    }
    return total;
}

int main(){
    int arr[4] = {1 , 2, 3, 4};

    //Step 1
    //Create a future promise 
    std::promise<int>pr;

    // Step 2
    // A promise made is kept in future ! future and promise are connected 
    std::future<int>ft = pr.get_future();

    //Step 3 
    // We start a fact . Fact has to wait for the input . This waiting and accepting of input will happens 
    // at the same time as SumOfArray function executing
    std::future<int>ans = std::async(&fact , std::ref(ft));



    int result = SumOfArray(arr , 4);
    std::cout<<result<<"\n";

    // Fulfiling the promise 
    //Send the number we had assured to the compiler 
    int number = takeInput();   
    pr.set_value(number);    // this will notify the functions 
    
    std::cout<<ans.get()<<"\n";


}
/*
    std::async can be used in 2 situations
 
        A) to catch and a return value from a fuction or to handle exception from a function[because normal std:::thread instances cannot do it]
 
        B)[current program] To start a thread even wihtout the input paameter being ready (so that delay ca be used)
*/

/*
    pr--------------------->        ft--------------------->


*/