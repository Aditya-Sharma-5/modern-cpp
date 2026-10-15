#ifndef EXCEPTIONMESSAGE_H
#define EXCEPTIONMESSAGE_H

#include<stdexcept>

class ExceptionMessage
{
private:
    std::string _msg;
public:
    ExceptionMessage()=delete;
    ~ExceptionMessage()=default;
    ExceptionMessage(ExceptionMessage&&)=default;
    ExceptionMessage(const ExceptionMessage&)=default;
    ExceptionMessage& operator=(const ExceptionMessage&)=delete;
    ExceptionMessage& operator=(ExceptionMessage&&)=delete;
    ExceptionMessage(const std::string& msg) : _msg{msg}{}

    std::string what() const { return _msg; }
};

#endif // EXCEPTIONMESSAGE_H
