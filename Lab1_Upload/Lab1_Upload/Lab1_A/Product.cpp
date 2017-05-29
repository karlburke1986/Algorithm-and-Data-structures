#include "Product.h"

Product::Product()
{
	NetPrice = 0.0;
}

Product::Product(double Price)
{
	NetPrice = Price;
}

double Product::getGrossPrice()
{
	return (NetPrice * 1.21);
}
