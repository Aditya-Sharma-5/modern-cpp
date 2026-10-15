#include"Operation.h"

void RunFunctionalities(){
    Operation* ptr = Operation::GetInstance();

    ptr->CreateObjects();

    std::optional<Container> r1 = ptr->ReturnNInstances(2 , true);
    if(r1.has_value()){
        for(const  Vr& v : r1.value())
        {
            std::visit(
                [](auto && val){std::cout<<val<<"\n";} , 
                v
            );
        }
    }
}

int main(){

}