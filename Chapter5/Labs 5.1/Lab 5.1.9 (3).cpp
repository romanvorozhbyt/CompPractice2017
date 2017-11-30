

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class AdHocSquare
{
public:
	AdHocSquare(double side);
	void set_side(double side);
	double get_area();
private:
	double side;
};
class LazySquare
{
public:
	AdHocSquare(double side);
	void set_side(double side);
	double get_area();
private:
	double side;
	double area;
	bool side_changed;
};AdHocSquare::AdHocSquare(double side)
{
	this->set_side(side);
}
LazySquare::AdHocSquare(double side) : AdHocSquare*(double side) {}
void AdHocSquare::set_side(double side)
{
	if (side > 0)
	{
		this->side = side;
	}
}
double AdHocSquare::get_area()
{
	return this->side*this->side;
}

void LazySquare::set_side(double side)
{
	if (side > 0)
	{
		if (this->side == side)
		{
			this->side_changed = false;
		}
		else
		{
			this->side = side;
			this->side_changed = true;
		}
	}
}
double LazySquare::get_area()
{
	if (this->side_changed)
	{
		return area = side*side;
	}
	else
	{
		return area;
	}
}
int main()
{
	LazySquare l = new AdHocSquare(2.);
	cout << l.get_area()<<endl;
	l.set_side(2.);
	cout << l.get_area() << endl;
	l.set_side(4.);
	cout << l.get_area() << endl;

		return 0;
}



2:07 18.11.2017