#include"Brand.h"

std::ostream &operator<<(std::ostream &os, const Brand &rhs) {
    os << "_type: " << static_cast<int>(rhs._type)
       << " _unique_tm: " << rhs._unique_tm;
       for(int i=0;i<3;i++){
        os<<"_car "<<i+1<<" : "<<rhs._cars[i];
       }
    return os;
}

Brand::Brand(BrandType type, std::string id, std::vector<std::reference_wrapper<Car>> cars)
   : _type{type}, _unique_tm{id}, _cars{cars}
{
}
