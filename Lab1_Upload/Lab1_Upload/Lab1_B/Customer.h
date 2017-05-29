#include "Person.h"
#include <string>

#pragma once
#ifndef Customer_h
#define Customer_h

//Karl Burke

class Customer: public Person
{
public:
	Customer(std::string);
	void printname() const;
};


#endif // !Customer_h
