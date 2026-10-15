#include "Vehicle.h"

Vehicle::Vehicle(std::string id, std::string name, VehicleType type, float price, int year, bool ncap, bool owned)
: m_vehicle_id{id} , m_vehicle_model_name{name } , m_vehicle_type{type} , m_vehicle_price{price} , m_vehicle_manufacturing_year{year} , m_is_vehicle_ncap_certified{ncap} , m_is_vehicle_previously_owned{owned}
{
}


float Vehicle::InsurancePremiumCost()
{
    if(m_vehicle_type == VehicleType::TEST_VEHICLE){
        if(m_is_vehicle_previously_owned){
            return (0.08* m_vehicle_price);
        }
        else{
            return (0.06* m_vehicle_price);
        }
    }
    return (0.04*m_vehicle_price);
}


float Vehicle::CalculateGSTAmount()
{
    if(m_is_vehicle_previously_owned){
        return (0.1*m_vehicle_price);
    }
    return (0.08 * m_vehicle_price);
}

std::ostream &operator<<(std::ostream &os, const Vehicle &rhs)
{
    os << "m_vehicle_id: " << rhs.m_vehicle_id
       << " m_vehicle_model_name: " << rhs.m_vehicle_model_name
       << " m_vehicle_type: " <<static_cast<int>( rhs.m_vehicle_type)
       << " m_vehicle_price: " << rhs.m_vehicle_price
       << " m_vehicle_manufacturing_year: " << rhs.m_vehicle_manufacturing_year
       << " m_is_vehicle_ncap_certified: " << rhs.m_is_vehicle_ncap_certified
       << " m_is_vehicle_previously_owned: " << rhs.m_is_vehicle_previously_owned;
    return os;
}
