#include "Person.h"
#include <iostream>
using namespace std;

//Karl Burke

Person::Person(string nameIn)
{
	name = nameIn;
}

void Person::printname() const
{
	cout << "Name : " << name << endl;
}
