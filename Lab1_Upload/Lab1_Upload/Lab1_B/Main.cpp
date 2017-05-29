#include "Customer.h"
#include "Employee.h"
#include "Person.h"
#include <iostream>

using namespace std;

int main()
{
	/*
	Part 1-5

	Person* personPtr;
	personPtr = new Person("Mark");

	personPtr->printname();

	personPtr = new Employee("Tom", 34000);
	

	personPtr->printname();

	personPtr = new Customer("Ed");

	personPtr->printname();

	*/
	
	Person *persons[3];

	persons[0] = new Employee("Tom", 12500);
	persons[1] = new Customer("Steve");
	persons[2] = new Employee("Rob", 30000);

	for (int i = 0; i < 3; i++)
	{
		persons[i]->printname();
	}

	system("PAUSE");
	
	return 0;
}
