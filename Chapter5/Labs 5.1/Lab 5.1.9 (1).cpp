
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
	string name;
	int age;
	string carNumber;
	double salary;
	void print();
};
void Person::print()
{
	cout << this->name<< " is "<< this->age << " years old. Salary: "<<this->salary << endl;
}

int main()
{
	Person person;
	person.name = "Harry";
	person.age = 23;
	cout << "Meet " << person.name<<endl;
	person.salary = 1.2333;
	person.print();
	// Your code here
	return 0;
}



