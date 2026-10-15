#ifndef OPERATION_H
#define OPERATION_H

#include<iostream>
#include<thread>
#include<memory>
#include<mutex>
#include<condition_variable>
#include<future>

class Operation
{
private:
    int m_value{0};
    std::mutex m_mt;
    std::condition_variable cv;
    bool m_is_input_received{false};

    static std::shared_ptr<Operation> m_instance ; 

    Operation() = default;

    Operation(const Operation &) = delete;
    Operation( Operation &&) = delete;

    Operation& operator=(const Operation&) = delete;
    Operation& operator=(Operation&&) = delete;
public:
    static std::shared_ptr<Operation> getInstance();

    void TakeInput();
    void Square();
    int Factorial(int n);
    void operator()();

};

#endif // OPERATION_H
