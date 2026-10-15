// /*
//     Override Keyword:
//         when you want that compiler must check that , you only want to override the function , so 
//         the compiler checks and make sure that the function is override or not.

//     --> The function must be virtual for overriding it into chils class --> Runtime Polymorphism.


//     The reason that the compiler needs to go to the child to base class , so it requires vtable for the movement, And the vtable
//     is only create when the function is virtual .
// */

// #include<iostream>

// class Vehicle
// {
// private:
//     /* data */
// public:
//     Vehicle() {};
//     virtual void CalculateGst(){
//         std::cout<<"Vehicle GST \n";
//     }
//     ~Vehicle() {};
// };

// class EvVehicle : public Vehicle
// {
// private:
//     /* data */
// public:
//     EvVehicle() {};

//     // void CalculateGST() override{   ==> this shows error as name is not same 
//     void CalculateGst() override{
//         std::cout<<"Ev Vehicle GST \n";
//     }
//     ~EvVehicle() {};
// };
// int main(){
//     Vehicle* ptr ;
//     EvVehicle e1;
//     ptr = &e1; 
//     ptr->CalculateGst();
//     return 0 ;

// }

#include<iostream>
using namespace std ; 

class Vehicle{
    public:
    Vehicle(){

    }
    ~Vehicle(){}
    virtual void show() {
        cout<<"vehicle class"<<endl;
    }
};
class EvVehicle : public Vehicle{
    public:
    EvVehicle(){

    }
    ~EvVehicle(){}
    void show() final {
        cout<<" EV vehicle class"<<endl;
    }

};

int main(){
    Vehicle* bptr;
    // EvVehicle* bptr;
    EvVehicle e1;
    bptr = &e1;
    bptr->show();
    // e1.show();
    return 0 ;
}