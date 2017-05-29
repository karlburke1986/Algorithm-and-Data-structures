#include "Product.h"

#pragma once
#ifndef Book_h
#define Book_h

//Karl Burke
//x00115288

class Book : public Product
{
public:
	Book(double price);
	double getGrossPrice();
};


#endif // !Book_h
