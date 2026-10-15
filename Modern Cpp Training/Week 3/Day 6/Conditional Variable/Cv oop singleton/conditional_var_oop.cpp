#include"Operation.h"

int main(){
    std::shared_ptr<Operation> obj = Operation::getInstance();

    // std::thread t1(&Operation::TakeInput , *obj);
    // std::thread t2(&Operation::Square , *obj);

    // std::future<int>result = std::async(&Operation::Factorial , *obj , 5);

    // t1.join();
    // t2.join();
    // std::cout<<result.get();
    (*obj)();
}