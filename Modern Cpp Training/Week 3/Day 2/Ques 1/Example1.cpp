#include<iostream>
#include<thread>
using DataContainer = std::array<int, 5>;
using ResultContainer = std::array<int , 10>;

ResultContainer result;

void square(const DataContainer& data){
    /*
        For every element "copied" from data into the variable val;
    */

   unsigned short k = 0;
   for(const int& val : data)
   {    
        // Artificial delay : to mimic or simulate real world situation, where delays happen naturally
        std::this_thread::sleep_for(std::chrono::seconds(1));
        result[k++] = val*val;
   }
}

void cube(const DataContainer& data){
    /*
        For every element "copied" from data into the variable val;
    */

   unsigned short k = 5;
   for(const int& val : data)
   {    
        // Artificial delay : to mimic or simulate real world situation, where delays happen naturally
        std::this_thread::sleep_for(std::chrono::seconds(1));
        result[k++] = val*val*val;
   }
}

void Display(const ResultContainer& data){
    for(const int& val : data){
        std::cout<<val<<" ";
    }
}
int main(){
    DataContainer arr{1 , 2, 3, 4, 5};

    std::thread t1(&square , std::ref(arr));
    std::thread t2(&cube , std::ref(arr));

    t1.join();   // hold the main thread and wait for t1 to signal completion/termination

    std::cout<<"this statement\n";   // only execute after t1 is complete

    t2.join();   // now ask t2 , main geets bolcked again till t2 signals completion/terminations
    // square(arr);
    // cube(arr);

    Display(result);
    return 0 ;
}

/* 



                            t1 lifecycle-------> k = 0  -------------> for loop -------------------------->\
                                                                                                            \
    -------> [main thread starts]---->t1 is instantiated----------> t2 is instantiated//////[HOLD MAIN YHREAD]////////| ////// ---> DISPLAY------> END
                                                                                                            /
                                                            t2 ----> k = 5  -----> for loop--------------->/
*/