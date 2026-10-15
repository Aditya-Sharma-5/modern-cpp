#include "Permit.h"
std::ostream &operator<<(std::ostream &os, const Permit &rhs) {
    os << "_id: " << rhs._id
       << " _permit_issue_year: " << rhs._permit_issue_year
       << " _permit_issue_rto: " << rhs._permit_issue_rto;
    return os;
}

Permit::Permit(std::string id, int permit_issue_year, std::string permit_issue_rto)
: _id{id}, _permit_issue_year{permit_issue_year} , _permit_issue_rto{permit_issue_rto}
{
}