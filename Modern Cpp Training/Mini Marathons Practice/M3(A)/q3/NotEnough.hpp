#ifndef NotEnough_HPP
#define NotEnough_HPP

#include <future>
#include <cstring>

class NotEnough : public std::future_error
{
private:
    char* m_msg;
public:
    NotEnough(std::future_errc error_type, const char* msg) : std::future_error{error_type} {
        m_msg = new char[strlen(msg) + 1];
        std::strcpy(m_msg, msg);
    }

    NotEnough(const NotEnough&) = delete;
    NotEnough(NotEnough&&) noexcept = default;
    NotEnough& operator=(const NotEnough&) = delete;
    NotEnough&& operator=(NotEnough&&) = delete;

    ~NotEnough() {
        delete[] m_msg;
    }

    const char* what() const noexcept override {
        return m_msg;
    }
};

#endif // NotEnough_HPP