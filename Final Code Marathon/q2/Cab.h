#ifndef CAB_H
#define CAB_H

#include<iostream>
#include"CabFuelType.h"
#include"CabStatus.h"
#include"CabType.h"

class Cab
{
private:
    std::string m_cab_reg_number ;
    CabType m_cab_type;
    CabStatus m_cab_status;
    unsigned int m_cab_seat_count;
    CabFuelType m_cab_fuel_type;
    bool m_is_cab_insured;
public:
    Cab() = default;
    ~Cab() = default;

    Cab(const Cab&) = default;
    Cab(Cab&&) = default;

    Cab& operator=(const Cab&) = default;
    Cab& operator=(Cab&&) = default;

    Cab(std::string reg , CabType type , CabStatus status , unsigned int seat , CabFuelType ftype , bool insured);

    std::string cabRegNumber() const { return m_cab_reg_number; }
    void setCabRegNumber(const std::string &cab_reg_number) { m_cab_reg_number = cab_reg_number; }

    CabType cabType() const { return m_cab_type; }
    void setCabType(const CabType &cab_type) { m_cab_type = cab_type; }

    CabStatus cabStatus() const { return m_cab_status; }
    void setCabStatus(const CabStatus &cab_status) { m_cab_status = cab_status; }

    unsigned int cabSeatCount() const { return m_cab_seat_count; }
    void setCabSeatCount(unsigned int cab_seat_count) { m_cab_seat_count = cab_seat_count; }

    CabFuelType cabFuelType() const { return m_cab_fuel_type; }
    void setCabFuelType(const CabFuelType &cab_fuel_type) { m_cab_fuel_type = cab_fuel_type; }

    bool isCabInsured() const { return m_is_cab_insured; }
    void setIsCabInsured(bool is_cab_insured) { m_is_cab_insured = is_cab_insured; }

    friend std::ostream &operator<<(std::ostream &os, const Cab &rhs);
};
#endif // CAB_H
