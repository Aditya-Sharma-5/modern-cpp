#ifndef CONDITIONNOTMATCHERROR_H
#define CONDITIONNOTMATCHERROR_H

#include<stdexcept>

class ConditionNotMatchError: public std::exception
{
private:
    std::string _msg;
public:
    ConditionNotMatchError(const std::string& msg)
    : _msg{msg} {}

    ~ConditionNotMatchError() {}

    ConditionNotMatchError(const ConditionNotMatchError&) = delete;
    ConditionNotMatchError(ConditionNotMatchError&&) = default;

    ConditionNotMatchError& operator=(const ConditionNotMatchError&) = delete;
    ConditionNotMatchError& operator=(ConditionNotMatchError&&) = default;
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    };

    std::string msg() const { return _msg; }


    // FUnction to convert string into a character
};

#endif // CONDITIONNOTMATCHERROR_H
