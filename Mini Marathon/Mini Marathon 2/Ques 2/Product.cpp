#include "Product.h"

Product::Product(std::string id, ProductType type, float price, std::string brand, ProductOrigin origin)
: _product_id{id} , _product_type{type} , _product_price{price} , _product_brand{brand} , _product_origin{origin}
{
    _product_tax_amount = 0.05* _product_price;
}
std::ostream &operator<<(std::ostream &os, const Product &rhs) {
    os << "_product_id: " << rhs._product_id
       << " _product_type: " <<static_cast<int>( rhs._product_type)
       << " _product_price: " << rhs._product_price
       << " _product_brand: " << rhs._product_brand
       << " _product_origin: " <<static_cast<int>( rhs._product_origin)
       << " _product_tax_amount: " << rhs._product_tax_amount;
    return os;
}
