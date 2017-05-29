#include "Employee.h"
#include <iostream>
using namespace std;

//Karl Burke

Employee::Employee(std::string nameIn, int salaryIn):Person(nameIn)
{
	salary = salaryIn;
}

void Employee::printname() const 
{
	cout << "Name : " << name
		<< " Salary : " << salary << endl;
}
