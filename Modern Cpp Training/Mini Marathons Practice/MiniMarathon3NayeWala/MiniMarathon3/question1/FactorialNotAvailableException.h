#ifndef FACTORIALNOTAVAILABLEEXCEPTION_H
#define FACTORIALNOTAVAILABLEEXCEPTION_H

#include<stdexcept>
#include<cstring>
class FactorialNotAvailableException :public std::exception
{
private:
    char * _msg;
public:
    
    FactorialNotAvailableException() =delete;
    FactorialNotAvailableException (const FactorialNotAvailableException &) =delete;                  //(delete -> disabled copy constructor )
    FactorialNotAvailableException(FactorialNotAvailableException &&)=default;                         //brand new
    FactorialNotAvailableException &operator=(const FactorialNotAvailableException&)=delete;          //deleted copy assignment
    FactorialNotAvailableException && operator=(FactorialNotAvailableException&&)=delete;  
    FactorialNotAvailableException(const char * msg) {
        // strlen(msg)
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }
    ~FactorialNotAvailableException() {
        delete [] _msg;
    }


    virtual const char * what() const noexcept{
        return _msg;
    }
};

#endif // FACTORIALNOTAVAILABLEEXCEPTION_H
