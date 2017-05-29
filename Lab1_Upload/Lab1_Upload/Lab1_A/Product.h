#pragma once
#ifndef Product_h
#define Product_h
//Karl Burke 
//x00115288

class Product
{
public:
	Product();
	Product(double Price);
	double getGrossPrice();

protected:
	double NetPrice;
};

#endif