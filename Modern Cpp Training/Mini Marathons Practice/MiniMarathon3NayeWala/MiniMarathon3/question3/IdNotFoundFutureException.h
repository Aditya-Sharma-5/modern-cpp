#ifndef IDNOTFOUNDFUTUREEXCEPTION_H
#define IDNOTFOUNDFUTUREEXCEPTION_H

#include<stdexcept>
#include<future>
#include<cstring>
class IdNotFoundFutureException :public std::future_error
{
private:
    char * _msg;
public:
    
    IdNotFoundFutureException() =delete;
    IdNotFoundFutureException (const IdNotFoundFutureException &) =delete;                  //(delete -> disabled copy constructor )
    IdNotFoundFutureException(IdNotFoundFutureException &&)=default;                         //brand new
    IdNotFoundFutureException &operator=(const IdNotFoundFutureException&)=delete;          //deleted copy assignment
    IdNotFoundFutureException && operator=(IdNotFoundFutureException&&)=delete;  
    IdNotFoundFutureException(std::future_errc ec, const char * msg) : std::future_error(ec) {
        // strlen(msg)
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }
    ~IdNotFoundFutureException() {
        delete [] _msg;
    }


    virtual const char * what() const noexcept{
        return _msg;
    }
};

#endif // IDNOTFOUNDFUTUREEXCEPTION_H
