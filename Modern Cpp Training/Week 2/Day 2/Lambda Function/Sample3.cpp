#include<iostream>
#include<functional>

void Adaptor( std::function<void()>fn){
    fn();
}


int main(){
    std::string name = "harshit";

    // f1 captures name by reference
    auto f1 = [&name](){std::cout<<name;};
    Adaptor(f1);
    
    auto f2 = [&name](){name = std::string{"magic"} ; std::cout<<name<<"\n";};

    Adaptor( f2);

    std::cout<<"Data inside name after f2 is called : "<<name<<"\n";


    Adaptor([&name](){name = "C++";});
    std::cout<<"Data inside name after f2 is called : "<<name<<"\n";
    return 0 ;
}

/*
Wherever the lambda goes , all the closure data goes 
*/