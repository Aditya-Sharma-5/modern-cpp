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
    ExceptionMessage(const ExceptionMessage&&)=delete;
    ExceptionMessage(ExceptionMessage&&)=default;
    ExceptionMessage& operator=(ExceptionMessage&&)=delete;
    ExceptionMessage& operator=(const ExceptionMessage&)=delete;
    ExceptionMessage(std::string msg): _msg{msg}{}

    std::string what() const { return _msg; }
};

#endif // EXCEPTIONMESSAGE_H
