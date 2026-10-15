#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include"ProductOrigin.h"
#include"ProductType.h"

class Product
{
private:
    std::string _product_id{""};
    ProductType _product_type{ProductType::PERFUME};
    float _product_price{0.0f};
    std::string _product_brand{""};
    ProductOrigin _product_origin{ProductOrigin::DOMESTIC};
    float _product_tax_amount{0.0f};
public:
    Product() = default;
    ~Product() = default;

    Product(const Product&) = default;
    Product(Product&&) = default;

    Product& operator=(const Product&) = default;
    Product& operator=(Product&&) = default;

    Product(std::string id , ProductType type , float price , std::string brand , ProductOrigin origin );

    std::string productId() const { return _product_id; }
    void setProductId(const std::string &product_id) { _product_id = product_id; }

    ProductType productType() const { return _product_type; }
    void setProductType(const ProductType &product_type) { _product_type = product_type; }

    float productPrice() const { return _product_price; }
    void setProductPrice(float product_price) { _product_price = product_price; }

    std::string productBrand() const { return _product_brand; }
    void setProductBrand(const std::string &product_brand) { _product_brand = product_brand; }

    ProductOrigin productOrigin() const { return _product_origin; }
    void setProductOrigin(const ProductOrigin &product_origin) { _product_origin = product_origin; }

    float productTaxAmount() const { return _product_tax_amount; }
    void setProductTaxAmount(float product_tax_amount) { _product_tax_amount = product_tax_amount; }

    friend std::ostream &operator<<(std::ostream &os, const Product &rhs);
};

#endif // PRODUCT_H
