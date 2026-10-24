/*
    1)  Resources are used in specific sections of the program.
            e.g : I want to save data from the frontend into my database
                -> Save Data(Employee obj )
                ->connect to data , fetch the data , create query , commit , close ;

    b) SCOPE exists for things(data)
    c)Connect resources to OBJECTS SO THAT LIFETIME OF OBJECTS (SCOPE OF OBJECTS) can be used to deal 
        with resources 
        - construction of objects === allocating the objects
        - (use constructor to object to acquire resources)
        - destruction of objects === deallocating resources.


        # Scope Based Resouces Management[SBRM]
        # Resource Acquisition Is Initialization [RAII] -------- (Official)
            The whole idea of allocation & deallocation of resources.
*/
#include<iostream>

class Wrapper
{
private:
    int* _ptr;
public:
    Wrapper(int* p): _ptr{p} {}
    ~Wrapper() {delete _ptr;}
    int* ptr() const {return _ptr;}
};

void Allocate(){
    Wrapper p(new int());
    *(p.ptr());
}