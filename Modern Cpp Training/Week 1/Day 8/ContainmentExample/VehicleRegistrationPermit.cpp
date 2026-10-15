#include "VehicleRegistrationPermit.h"
std::ostream &operator<<(std::ostream &os, const VehicleRegistrationPermit &rhs) {
    os << "_permit_id: " << rhs._permit_id
       << " _permit_issue_year: " << rhs._permit_issue_year
       << " _permit_issue_rto: " << rhs._permit_issue_rto;
    return os;
}

VehicleRegistrationPermit::VehicleRegistrationPermit(std::string permit_id, int16_t permit_issue_year, std::string permit_issue_rto)
: _permit_id{permit_id} , _permit_issue_year{permit_issue_year} , _permit_issue_rto{permit_issue_rto}
{
}