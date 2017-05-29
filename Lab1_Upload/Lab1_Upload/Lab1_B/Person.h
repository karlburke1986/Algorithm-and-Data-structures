#pragma once
#ifndef Person_h
#define Person_h
#include <string>
//Karl Burke

/*
Part 1-5
class Person
{
public:
Person(std::string); // initialise the name
virtual void printname();
protected:
std::string name;
};
*/

class Person
{
public:
	Person(std::string); // initialise the name
	virtual void printname() const = 0;

protected:
	std::string name;
};


#endif // !Person_h
