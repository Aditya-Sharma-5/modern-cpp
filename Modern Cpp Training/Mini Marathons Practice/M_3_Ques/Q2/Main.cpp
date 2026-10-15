#include"Operation.h"

int main(){
    Container data;
    Operation* ptr = Operation::GetInstance();
    try{
    ptr->CreateObjects(data);
    ptr->MapThread(ptr,data);
    ptr->JoinThread();

    // ptr->AutomobilesAboveSeatCount4(data);
    // ptr->AverageAutomobilePrice(data);
    // ptr->AverageGSTOfEvCars(data);
    // ptr->IfAnyDCType(data);
    }
    catch(ExceptionMessage& ex){
        std::cout<<ex.what()<<std::endl;
    }
}