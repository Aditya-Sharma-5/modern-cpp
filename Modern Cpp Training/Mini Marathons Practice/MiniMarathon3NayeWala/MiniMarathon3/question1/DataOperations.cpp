#include "DataOperations.h"
#include "EmptyContainerException.h"
#include "NumberException.h"
#include "FactorialNotAvailableException.h"

std::shared_ptr<DataOperations> DataOperations::_object{nullptr};
DataOperations::DataOperations(std::vector<int> data): _dataVector{data}{
    
}
void DataOperations::FindMax()
{
    if(_dataVector.empty()){
        throw EmptyContainerException("Data is Empty!");
    }
    
    int max=_dataVector[0];

    for(int i:_dataVector){
        if(max<i){
            max=i;
        }

    }
    std::lock_guard<std::mutex> lg(mt);
    std::cout<<"The maximum number in the _dataVector is : "<<max<<std::endl;

}

void DataOperations::SumOfFirstN(int N)
{
    if(_dataVector.empty()){
        throw EmptyContainerException("Data is Empty!");
    }
    if(N<0 || N>=_dataVector.size()){
        throw NumberException("Invalid Number range !");
    }
    int sum=0;
    for(int i=0;i<N;i++){
        sum+=_dataVector[i];
    }

    std::lock_guard<std::mutex> lg(mt);
    std::cout<<"The Sum of First N number in _dataVector is : "<<sum<<std::endl;
}

void DataOperations::FindNthValue(int N)
{
    if(_dataVector.empty()){
        throw EmptyContainerException("Data is Empty!");
    }
    if(N<0 || N>=_dataVector.size()){
        throw NumberException("Invalid Number range !");
    }
    std::lock_guard<std::mutex> lg(mt);
    std::cout<<"The number at Nth index in _dataVector is : "<<_dataVector[N]<<std::endl; 
}

void DataOperations::FindOddNumbers()
{
    if(_dataVector.empty()){
        throw EmptyContainerException("Data is Empty!");
    }

    std::lock_guard<std::mutex> lg(mt);
    std::cout<<"Odd numbers in _dataVector are : ";
    for(int i:_dataVector){
        if(i%2!=0){
            std::cout<<i<<" ";
        }
    }
    std::cout<<"\n";
}

void DataOperations::FindFactorial()
{
    if(_dataVector.empty()){
        throw EmptyContainerException("Data is Empty!");
    }
    
    for(int i:_dataVector){
        if(i>=1  && i<=10){
            int fac=1;
            for(int j=1;j<=i;j++){
                fac*=j;
            }
            std::lock_guard<std::mutex> lg(mt);
            std::cout<<"The factorial of "<<i<<" is: "<< fac<<std::endl;
        }
        else{
            throw FactorialNotAvailableException("Not is valid number to Find Factorial !");
        }
    }

}

void DataOperations::TakeInput()
{
    std::lock_guard<std::mutex> lg(mt);
    std::cout<<"Enter the value for _magic number : ";
    std::cin>>_magicNumber;
    flag=true;
    CVariable.notify_one();
}

void DataOperations::CheckPrime()
{
    std::unique_lock<std::mutex> ul(mt);
    CVariable.wait(ul,[&](){
        return flag;
    });
    bool flag2=true;
    for(int i=2;i<_magicNumber;i++){
        if(_magicNumber%i==0){
            flag2=false;
            std::cout<<"The is not a prime number!"<<std::endl;
            break;
        }
    }
    if(flag2){
        std::cout<<"_magicNumber is a prime number!"<<std::endl;
    }

}

std::shared_ptr<DataOperations> DataOperations::createInstance(std::vector<int> vec)
{
    if(_object){
        return _object;

    }
    else{
        _object.reset(new DataOperations(vec));
        return _object;
    }
}
