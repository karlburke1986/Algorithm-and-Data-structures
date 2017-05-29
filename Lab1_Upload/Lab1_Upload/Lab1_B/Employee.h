#include "Person.h"

#pragma once
#ifndef Employee_h
#define Employee_h
#include <string>

//Karl Burke

class Employee: public Person
{
public:
	Employee(std::string, int);
	void printname() const;

private:
	int salary;
};


#endif // !Employee_h
