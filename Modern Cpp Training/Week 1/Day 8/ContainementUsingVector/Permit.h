#ifndef PERMIT_H
#define PERMIT_H

#include<iostream>
class Permit
{
private:
    std::string _id{""};
    int _permit_issue_year{2005};
    std::string _permit_issue_rto{""};
public:
    Permit() = delete;
    ~Permit() = default;

    Permit(const Permit&) = delete;
    Permit(Permit&&) = delete;

    Permit& operator=(const Permit&) = delete;
    Permit& operator=(Permit&&) = delete;

    Permit(std::string id , int permit_issue_year , std::string permit_issue_rto);

    std::string id() const { return _id; }

    int permitIssueYear() const { return _permit_issue_year; }

    std::string permitIssueRto() const { return _permit_issue_rto; }

    friend std::ostream &operator<<(std::ostream &os, const Permit &rhs);
};

#endif // PERMIT_H
