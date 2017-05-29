#include "Customer.h"
#include <iostream>

using namespace std;

//Karl Burke

Customer::Customer(std::string nameIn):Person(nameIn)
{
}

void Customer::printname() const
{
	cout << "Name : " << name << " wishes to make a complaint" << endl;
}
