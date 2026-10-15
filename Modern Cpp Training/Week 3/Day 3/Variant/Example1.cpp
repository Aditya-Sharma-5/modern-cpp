/* 
    Objective: Creating a variant of either std::string or integer
    [Understand the basic syntax of variant creation and access]
*/

#include<variant>
#include<iostream>

/*
    2 Actions : square of int , lemgth of string 
    Actions are specific to variant  type 
*/


void performOperation(std::variant<int , std::string>& v){
    if(std::holds_alternative<int>(v)){
        int value = std::get<0>(v);
        std::cout<<"Square of "<<value<<" is : "<<value*value<<"\n";
    }
    else{
        std::string& data = std::get<1>(v);
        std::cout<<"Length is : "<<data.length()<<"\n";
    }
}

void CommonOPeration(std::variant<int , std::string>& v){
    /*
        Print the output value for both 
    */
   /*
        visit will oper the variant 
        It will find either a int or a string . Whatever is found , we will call it "val"
   */

   std::visit(
    [](auto&& val){std::cout<<val;},
    v
   );

}

int main(){
    std::variant<int , std::string> vr;
    vr = 10 ; 
    performOperation(vr);

    vr = "Aadi";
    performOperation(vr);

    CommonOPeration(vr);
    return 0 ;

}