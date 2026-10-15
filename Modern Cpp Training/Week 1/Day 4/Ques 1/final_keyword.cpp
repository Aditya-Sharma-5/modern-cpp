
/*final - keyword 
    1) final keyword is used when you don't want your class have a child class.
    2) final keyword can be used with Virtual Function so that it cannot be override.
*/


#include<iostream>


// It gives error
// class Demo final {};
// class ExtendedDemo : public Demo{};

class Demo{
    public:
        Demo(){};
        ~Demo(){};

    virtual void show() final{};
};