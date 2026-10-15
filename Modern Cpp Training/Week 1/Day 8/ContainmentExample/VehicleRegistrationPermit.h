#ifndef VEHICLEREGISTRATIONPERMIT_H
#define VEHICLEREGISTRATIONPERMIT_H

#include<iostream>

class VehicleRegistrationPermit
{
private:
    std::string _permit_id;
    int16_t _permit_issue_year; //using this for storing 16 bit 
    std::string _permit_issue_rto;
public:
    VehicleRegistrationPermit() = delete ; 
    ~VehicleRegistrationPermit() = default ; 

    VehicleRegistrationPermit(const VehicleRegistrationPermit&) = delete;
    VehicleRegistrationPermit(VehicleRegistrationPermit&&) = delete;

    VehicleRegistrationPermit& operator=(const VehicleRegistrationPermit&) = delete;
    VehicleRegistrationPermit& operator=(VehicleRegistrationPermit&&) = delete;

    VehicleRegistrationPermit(std::string permit_id , int16_t permit_issue_year , std::string permit_issue_rto);

    std::string permitId() const { return _permit_id; }

    int16_t permitIssueYear() const { return _permit_issue_year; }

    std::string permitIssueRto() const { return _permit_issue_rto; }

    friend std::ostream &operator<<(std::ostream &os, const VehicleRegistrationPermit &rhs);
};

#endif // VEHICLEREGISTRATIONPERMIT_H
