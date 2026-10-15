#ifndef OPERATION_H
#define OPERATION_H

#include<vector>
#include<iostream>
#include<thread>
#include<memory>
#include<mutex>

/*
    Container 
*/
using IntegerContainer = std::vector<int>;
using StringContainer = std::vector<std::string>;
using ThreadVector = std::vector<std::thread>;


class Operation
{
private:
    static std::shared_ptr<Operation> m_instance;
    unsigned int m_size;
    IntegerContainer m_integer_vector;
    StringContainer m_string_container;
    ThreadVector m_thread_vector;
    std::mutex m_mt;

    // ------------ Special Member Function ------------------
    Operation() = default;

    Operation(IntegerContainer data1 , StringContainer data2):m_integer_vector{data1} , m_string_container{data2}{}

    Operation(const Operation&) = delete;
    Operation(Operation&&) = delete;

    Operation& operator=(const Operation&) = delete;
    Operation& operator=(Operation&&) = delete;
public:

//------------------ Default Destructor ------------------------
    ~Operation() = default;

// This funuction displays the sum of odd numbers present in the data container.
    void SumOfOdd();


// This funuction displays the prime numbers present in the data container.
    void FilterPrimeNumbers();


//This function displays the string having maximum length.
    void FindLargestString();


// This funuction displays the once occuring elements present in the data container.
    void OnceOccuringNumbers();

//This function display the First Vowel of the string 
    void DisplayFirstVowel();


// This function is used to create the thread 
    void MapThreads();

//this function is used to join the thread in the main function.
    void JoinThreads();

// This is static function whuich is used to create the single object of the Operation class
    static std::shared_ptr<Operation> getInstance(IntegerContainer data1 , StringContainer data2);
};

#endif // OPERATION_H
