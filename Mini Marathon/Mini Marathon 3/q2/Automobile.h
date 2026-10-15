#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include"AutomobileCategory.h"
#include"AutomobileWheelType.h"
#include<iostream>
#include"InvalidInputError.h"


class Automobile
{
private:
    std::string m_automobile_id;
    unsigned int m_automobile_seat_count ; 
    AutomobileCategory m_automobile_category;
    unsigned int m_automobile_manufacturing_year;
    float m_automobile_price;
    AutomobileWheelType m_automobile_wheel_type;
    bool m_is_automobile_ncap_certified;

public:
    Automobile() = delete;
    ~Automobile() = default;

    Automobile(const Automobile&) = default;
    Automobile( Automobile&&) = default;

    Automobile& operator=(const Automobile&) = default;
    Automobile& operator=(Automobile&&) = default;

    Automobile(std::string id , unsigned int seat , AutomobileCategory category , unsigned int year , float price , AutomobileWheelType wtype , bool ncap);

    std::string automobileId() const { return m_automobile_id; }
    void setAutomobileId(const std::string &automobile_id) { m_automobile_id = automobile_id; }

    unsigned int automobileSeatCount() const { return m_automobile_seat_count; }
    void setAutomobileSeatCount(unsigned int automobile_seat_count) { m_automobile_seat_count = automobile_seat_count; }

    AutomobileCategory automobileCategory() const { return m_automobile_category; }
    void setAutomobileCategory(const AutomobileCategory &automobile_category) { m_automobile_category = automobile_category; }

    unsigned int automobileManufacturingYear() const { return m_automobile_manufacturing_year; }
    void setAutomobileManufacturingYear(unsigned int automobile_manufacturing_year) { m_automobile_manufacturing_year = automobile_manufacturing_year; }

    float automobilePrice() const { return m_automobile_price; }
    void setAutomobilePrice(float automobile_price) { m_automobile_price = automobile_price; }

    AutomobileWheelType automobileWheelType() const { return m_automobile_wheel_type; }
    void setAutomobileWheelType(const AutomobileWheelType &automobile_wheel_type) { m_automobile_wheel_type = automobile_wheel_type; }

    bool isAutomobileNcapCertified() const { return m_is_automobile_ncap_certified; }
    void setIsAutomobileNcapCertified(bool is_automobile_ncap_certified) { m_is_automobile_ncap_certified = is_automobile_ncap_certified; }

    friend std::ostream &operator<<(std::ostream &os, const Automobile &rhs);
    
};
#endif // AUTOMOBILE_H
