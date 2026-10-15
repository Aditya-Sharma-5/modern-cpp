#ifndef BUSSINESSOWNER_H
#define BUSSINESSOWNER_H

#include<iostream>
#include"BussinessType.h"

class BussinessOwner
{
private:
    std::string m_registered_name{"Aadi"};
    BussinessType m_bussinessType{BussinessType::PVT_LTD};
    std::string m_bussiness_location{"Pune"};
    float m_profit{0.0f};
public:
    BussinessOwner() = default;
    ~BussinessOwner() = default;

    BussinessOwner(const BussinessOwner&) = default;
    BussinessOwner(BussinessOwner&&) = default;

    BussinessOwner& operator=(const BussinessOwner&) = delete;
    BussinessOwner& operator=(BussinessOwner&&) = delete;

    BussinessOwner(std::string name , BussinessType type , std::string location , float profit);

    float CalculateTaxAmount() const;

    std::string registeredName() const { return m_registered_name; }
    void setRegisteredName(const std::string &registered_name) { m_registered_name = registered_name; }

    BussinessType bussinessType() const { return m_bussinessType; }
    void setBussinessType(const BussinessType &bussinessType) { m_bussinessType = bussinessType; }

    std::string bussinessLocation() const { return m_bussiness_location; }

    void setBussinessLocation(const std::string &bussiness_location) { m_bussiness_location = bussiness_location; }

    float profit() const { return m_profit; }
    void setProfit(float profit) { m_profit = profit; }

    friend std::ostream &operator<<(std::ostream &os, const BussinessOwner &rhs);
};

#endif // BUSSINESSOWNER_H
