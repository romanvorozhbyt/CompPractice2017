#include <iostream>
#include <string>
using namespace std;
//add your own exception class here
class Class {
public:
	string msg;
	Class(string txt) :msg(txt) { }
};
//add functions code here
float square_area(float a)
{
	return a*a;
}
float rectangle_area(float a, float b)
{
	return a*b;
}
int main(void) {
	float a, b, r;
	cin >> a;
	cin >> b;
	try
	{
		if (a <= 0 || b <= 0)
			throw Class("The area can't be negative.");
		float rsquare = square_area(a);
		float rrectangle = rectangle_area(a, b);
		cout << rsquare << endl << rrectangle << endl;
	}
	//add a suitable catch block here
	catch (Class &exp)
	{
		cout << "Your input is not valid. "<< exp.msg << endl;
	}
	return 0;
}
