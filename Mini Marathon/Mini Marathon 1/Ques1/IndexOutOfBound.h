#ifndef INDEXOUTOFBOUND_H
#define INDEXOUTOFBOUND_H


#include<stdexcept>

class IndexOutOfBound: public std::exception
{
private:
    std::string _msg;
public:
    IndexOutOfBound(const std::string& msg)
    : _msg{msg} {}

    ~IndexOutOfBound() {}

    IndexOutOfBound(const IndexOutOfBound&) = delete;
    IndexOutOfBound(IndexOutOfBound&&) = default;

    IndexOutOfBound& operator=(const IndexOutOfBound&) = delete;
    IndexOutOfBound& operator=(IndexOutOfBound&&) = default;
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    };

    std::string msg() const { return _msg; }


    // FUnction to convert string into a character
};

#endif // INDEXOUTOFBOUND_H
