// #include<iostream>
// using namespace std ; 
// class Demo{
//     int salary ;
//     string name; 
//     public: 
//     Demo(int s , string n){
//         salary = s;
//         name = n ;
//     }

//     void show(){
//         cout<<"The name is "<<name<<" and salary is "<<salary<<endl;
//     }
//     friend std::ostream &operator<<(std::ostream &os, const Demo &rhs) {
//         os << "salary: " << rhs.salary<<endl
//            << " name: " << rhs.name;
//         return os;
//     }
//     // void operator+(const Demo& obj){
//     //     cout<<"Both name is "<<(this->name+ " & " + obj.name)<<endl;
//     //     cout<<"Combined salary is "<<(salary + obj.salary)<<endl;
//     // }
//     // string operator+(const Demo& obj){
//     //     return (this->name+ " & " + obj.name);
//     // }
// };
// int main(){
//     // Demo d1(1100 , "Aadi");
//     // Demo d2(1200 , "Kamran");

//     // cout<<d1;
//     // // cout<<d2+d1;
//     // // d2.show();
//     // // d1.show();








//     // string s1 = "Jayesh "; 
//     // string s2 ; 
//     // int n1 ; 
//     int s1 = 10;
//     int s2 ; 
//     // s2 = s1 ; 
//     s2 = move(s1);
//     cout<<s1<<endl;
//     cout<<s2<<endl;
//     // cout<<n1<<endl;
//     return 0 ;
// }
#include<iostream>
using namespace std ; 

int main(){

    // string s1 = "Hii";
    // string s2;

    // s2 = s1;
    // s2 = move(s1);

    int s1 = 10;
    int s2 ; 
    // s2 = s1;
    s2 = move(s1);
    cout<<s1<<endl;
    cout<<s2<<endl;

    return 0 ;
}