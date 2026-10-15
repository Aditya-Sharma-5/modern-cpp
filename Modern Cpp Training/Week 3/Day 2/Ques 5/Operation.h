#ifndef OPERATION_H
#define OPERATION_H
#include<mutex>
#include<iostream>
#include<thread>
#include<list>

/*

        -data oriented
            -multiple objects with different values will be created

        -functionality oriented 
            - Achieve encapsulation. Execute operations. ONLY ONE OBJECT OF SUCH CLASS MAY BE SUFFIECIENT 
              TO RUN THE PROGRAM.
*/

/*
    Singleton Class:
        step 1) need a static data member
        step 2) Move all constructor to rivate , so that no one will able to create objects
*/

class Operation
{
private:
    std::mutex _mutex;
    int _amount{-1};
    std::list<std::thread>m_thread{};

    //Static Data Member : 
        //A shared memory area which will be accessed by all instance of the class . If any objects 
        // changes the value of a static data member , it will refelct in all objects.

    // Static member functions : such member can be modify static data.
    static Operation* m_object;


    explicit Operation(int amt);
    Operation() = default;

    Operation(const Operation&) = delete;
    Operation(Operation&&) = delete;

    Operation& operator=(const Operation&) = delete;
    Operation& operator=(Operation&&) = delete;


public:

    void withdraw();
    void deposit();
    void createThreads();
    void joinThreads();
    void Display();

    void operator()();

    static Operation* CreateObjects(int amt);

    ~Operation() = default;
};



#endif // OPERATION_H
