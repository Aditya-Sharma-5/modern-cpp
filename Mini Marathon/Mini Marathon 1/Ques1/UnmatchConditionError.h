#ifndef UNMATCHCONDITIONERROR_H
#define UNMATCHCONDITIONERROR_H

#include<stdexcept>

class UnmatchConditionError: public std::exception
{
private:
    std::string _msg;
public:
    UnmatchConditionError(const std::string& msg)
    : _msg{msg} {}

    ~UnmatchConditionError() {}

    UnmatchConditionError(const UnmatchConditionError&) = delete;
    UnmatchConditionError(UnmatchConditionError&&) = default;

    UnmatchConditionError& operator=(const UnmatchConditionError&) = delete;
    UnmatchConditionError& operator=(UnmatchConditionError&&) = default;
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    };

    std::string msg() const { return _msg; }


    // FUnction to convert string into a character
};

#endif // UNMATCHCONDITIONERROR_H
