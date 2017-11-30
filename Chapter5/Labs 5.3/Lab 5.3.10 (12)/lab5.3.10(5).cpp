#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Fraction {
public:
	Fraction(int numerator, int denominator);
	string toString();
	double toDouble();
private:
	int numerator;
	int denominator;
};
Fraction::Fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	if (denominator != 0)
	{
		this->denominator = denominator;
	}
	else this->denominator = 1;
	if (denominator < 0)
	{
		this->denominator = -this->denominator;
		this->numerator = -this->numerator;
	}
}
// implement Fraction methods
string Fraction::toString()
{
	string str;
	int integer = numerator / denominator;
	if (integer < 0)
	{
		numerator = -numerator;
	}
	if (numerator%denominator == 0)
	{
		str = to_string(integer);
	}
	else if(numerator/denominator>= 1)
	{
		str = to_string(integer);
		str += " "+ to_string(numerator%denominator) + "/" + to_string(denominator);
		
	}
	else
	{
		str = to_string(numerator) + "/" + to_string(denominator);
		
	}
	return str;
}
double Fraction::toDouble()
{
	return numerator*1.0 / denominator;
}
int main(void) {
	int num =0 , den=0;
	string input = "";
	// parse input and get numerator and denominator
	getline(cin,input);
	num = atoi(input.c_str());
	input = input.substr(input.find("/") + 1);
	den = atoi(input.c_str());
	Fraction fraction(num, den);
	cout << fraction.toString() << " is "<< fraction.toDouble()<<" in decimal "<< endl;
	return 0;
}