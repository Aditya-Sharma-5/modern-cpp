#include"Functionalities.h"

int main(){
    DataContainer data{1 , 2, 3, 4, 5};

    ResultContainer result;

    std::thread arr[2];

    arr[0] =  std::thread(&Square , std::ref(data) , std::ref(result));
    arr[1] =  std::thread(&Cube , std::ref(data) , std::ref(result));

    for(std::thread& th : arr){
        if(th.joinable()){
            th.join();
        }
    }

    Display(result);
    return 0 ;
}