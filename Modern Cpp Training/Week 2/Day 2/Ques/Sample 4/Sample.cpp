#include<iostream>

class Demo{
private:
    int m_id;
public:
    Demo(int n){
        m_id = n;
    }
    void operator()(int num)
    {
    std::cout<<"Square of number : "<<num*num<<"\n";}

};
int main(){
    Demo d1(10);
    d1(6);      //invoking/using () operator on type Demo object

    /*
        objects of a class are used as if they are function 
        [objects behave like functions]
            -functor objects
    */
}


/*
     Backend Portion of Lambda FUnction
        - Make a class with some random function 
        - Copy 
*/