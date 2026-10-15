#include<iostream>
#include<condition_variable>
#include<thread>
#include<future>

/*
    Objective : Take inout of 1 num from the user . Calculate the square of this input number 
                Also calculate the square 
*/

/*
    Producer Consumer Problem : 
*/
std::condition_variable cv;
bool m_is_input_received{false};
std::mutex mt;
int value = 0;

void TakeInput(){

    std::lock_guard<std::mutex>lk(mt);
    std::cin>>value;
    if(value != 0)
    {
        m_is_input_received= true;
        cv.notify_one();   // Value is produced 
    }
}

void square(){

    std::unique_lock<std::mutex>ul(mt);
    //Befor the signal will remain blocked 
    cv.wait(ul , [](){return m_is_input_received;});
    std::cout<<"Square of "<<value<<" is : "<<value*value<<"\n";
}

int Factorial(int n){
    if(n<0 ){
        throw std::runtime_error("Negative NUmber!!");
    }
    if(n==0 || n==1){
        return 1;
    }
    else{
        return n*Factorial(n-1);
    }
}

int main(){
    std::thread t0(TakeInput);

    std::thread t1(&square);

    ////////
    std::future<int>result = std::async(& Factorial, 5);
    t0.join();
    t1.join();
    std::cout<<result.get();

}

/*
    start the main thread 

    ----> I will run takeInput in a separeate std::thread
             ---> Input function will send a signal "event happened " to the consumer thread square 
    
    ----> I will run square in a seperate std::thread
             ---> wait for the signal . DO NOT PROCEED WITH calculation before the signal .
            NOTE : IF THERE IS AN EXCEPTION IN TAKEINPUT , signal will never be sent to square
*/


/*
    Scenario 1) 
                t1 scheduled first           ------->applies mutex ------>    input -----> flag true ------------> signal
        start--> main thread --->t1 is created ---////////////////----> t2 is created ------>      Factorial------------>
                                                                        ------> wait(signal) is caught


    Scenario 2)
        t2 scheduled first 
*/