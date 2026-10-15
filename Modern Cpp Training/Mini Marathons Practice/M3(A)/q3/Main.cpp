#include "Functionalities.hpp"

int main(int argc, char const *argv[])
{

    Container obj;
    CreateObject(obj);

    for(Vtype it: obj){
        std::visit([](auto&& val){ std::cout << *val << std::endl;},it);
    }

    try
    {
        /* code */
        std::future<Container> a = std::async(Ninstance,std::ref(obj),"ICECAR",1);
        if(Container val = a.get(); !val.empty()){
            for(auto it : val){
                std::visit([](auto&& vall){
                std::cout << *vall << '\n';},it);
            }
        }

        std::future<bool> b = std::async(IsOne,std::ref(obj));
        std::cout << b.get() << std::endl;

    }
    catch(const std::future_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
