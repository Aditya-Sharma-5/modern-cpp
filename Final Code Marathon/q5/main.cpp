#include"Operation.h"

int main(){
    std::shared_ptr<Operation> obj = Operation::getInstance();

    obj.get()->CreateObject();
    obj.get()->CreatePair();
    obj.get()->CreatePriorityQueue();
    obj.get()->CreateSet();

    obj.get()->createThread();
    obj.get()->JoinThread();
}