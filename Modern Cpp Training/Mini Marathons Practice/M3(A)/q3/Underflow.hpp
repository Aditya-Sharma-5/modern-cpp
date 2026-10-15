#ifndef Underflow_HPP
#define Underflow_HPP

#include <future>
#include <cstring>

class Underflow : public std::future_error
{
private:
    char* m_msg;
public:
    Underflow(std::future_errc error_type, const char* msg) : std::future_error{error_type} {
        m_msg = new char[strlen(msg) + 1];
        std::strcpy(m_msg, msg);
    }

    Underflow(const Underflow&) = delete;
    Underflow(Underflow&&) noexcept = default;
    Underflow& operator=(const Underflow&) = delete;
    Underflow&& operator=(Underflow&&) = delete;

    ~Underflow() {
        delete[] m_msg;
    }

    const char* what() const noexcept override {
        return m_msg;
    }
};

#endif // Underflow_HPP