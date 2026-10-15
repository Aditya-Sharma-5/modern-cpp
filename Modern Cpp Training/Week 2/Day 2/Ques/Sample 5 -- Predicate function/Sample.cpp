#include"functionality.h"

int main(){
    auto mod5 = [](const int num){return num%5==0;};
    Adaptor(
        std::list<int>{1 , 2, 3, 4, 5},
        mod5
    );
    return 0 ;
}