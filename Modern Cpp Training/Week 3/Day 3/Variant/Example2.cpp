/* 
    Objective: Creating a variant of either std::string or integer
    [Understand the basic syntax of variant creation and access]
*/

#include<variant>
#include<iostream>

#include<array>

using Vtype = std::variant<int , std::string>;
using Container = std::array<Vtype , 3>;

/*
    2 Actions : square of int , lemgth of string 
    Actions are specific to variant  type 
*/


void performOperation(Container& v){
    for(Vtype v:v)
    {
        if(std::holds_alternative<int>(v))
        {
            int value = std::get<0>(v);
            std::cout<<"Square of "<<value<<" is : "<<value*value<<"\n";
        }
        else
        {
            std::string& data = std::get<1>(v);
            std::cout<<"Length is : "<<data.length()<<"\n";
        }
    }
}

void CommonOPeration(Container& v){
    /*
        Print the output value for both 
    */
   /*
        visit will oper the variant 
        It will find either a int or a string . Whatever is found , we will call it "val"
   */
    for(Vtype v: v)
    {
        std::visit(
            [](auto&& val){std::cout<<val<<"\n";},
            v
        );
    }

}

int main(){
    Container vr;
    vr[0] = 10;
    vr[1] = "Aadi";
    vr[2] = "Be Positive";

    performOperation(vr);

    CommonOPeration(vr);
    return 0 ;

}