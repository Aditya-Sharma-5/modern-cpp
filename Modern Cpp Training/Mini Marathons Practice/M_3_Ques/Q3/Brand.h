#ifndef BRAND_H
#define BRAND_H

#include"BrandType.h"
#include"Car.h"
#include<functional>
#include<vector>
#include <ostream>

class Brand
{
private:
    BrandType _type;
    std::string _unique_tm;
    std::vector<std::reference_wrapper<Car>> _cars;
public:
    Brand()=delete;
    ~Brand()=default;
    Brand(const Brand&&)=delete;
    Brand(Brand&&)=delete;
    Brand& operator=(Brand&&)=delete;
    Brand& operator=(const Brand&)=delete;
    Brand(BrandType type, std::string id, std::vector<std::reference_wrapper<Car>> cars);

    BrandType type() const { return _type; }

    std::string uniqueTm() const { return _unique_tm; }

    std::vector<std::reference_wrapper<Car>> cars() const { return _cars; }


    friend std::ostream &operator<<(std::ostream &os, const Brand &rhs);
};

#endif // BRAND_H
