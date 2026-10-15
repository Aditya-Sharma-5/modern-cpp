#ifndef DATAOPERATIONS_H
#define DATAOPERATIONS_H
#include<iostream>
#include<vector>
#include<memory>
#include<condition_variable>
#include<mutex>
class DataOperations
{
private:
    /* data */
    std::vector<int> _dataVector; 
    unsigned int _magicNumber{0};
    DataOperations(std::vector<int> data);
    static std::shared_ptr<DataOperations> _object;
    std::mutex mt;
    std::condition_variable CVariable;
    bool flag=false;



public:
    DataOperations()=delete;
    DataOperations(const DataOperations &)=delete;
    DataOperations(DataOperations && )=delete;
    DataOperations & operator=(const DataOperations & )=delete;
    DataOperations &operator=(DataOperations &&)=delete;
    ~DataOperations()=default;

    static std::shared_ptr<DataOperations> createInstance(std::vector<int> vec);
    
    void FindMax();
    void SumOfFirstN(int N);
    void FindNthValue(int N);
    void FindOddNumbers();
    void FindFactorial();
    void TakeInput();
    void CheckPrime();


};

#endif // DATAOPERATIONS_H


