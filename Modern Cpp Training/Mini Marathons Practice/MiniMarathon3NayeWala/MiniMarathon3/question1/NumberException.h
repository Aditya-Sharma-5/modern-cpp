#ifndef NUMBEREXCEPTION_H
#define NUMBEREXCEPTION_H

#include<stdexcept>
#include<cstring>
class NumberException :public std::exception
{
private:
    char * _msg;
public:
    
    NumberException() =delete;
    NumberException (const NumberException &) =delete;                  //(delete -> disabled copy constructor )
    NumberException(NumberException &&)=default;                         //brand new
    NumberException &operator=(const NumberException&)=delete;          //deleted copy assignment
    NumberException && operator=(NumberException&&)=delete;  
    NumberException(const char * msg) {
        // strlen(msg)
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }
    ~NumberException() {
        delete [] _msg;
    }


    virtual const char * what() const noexcept{
        return _msg;
    }
};

#endif // NUMBEREXCEPTION_H
