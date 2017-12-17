#include <iostream>
#include <string>
using namespace std;
//add your own exception class here
class OutOfRangeExeption
{
	string _message;
public:
	OutOfRangeExeption(string message)
	{
		this->_message = message;
	}
	string Message()
	{
		return _message;
	}
};
class  ValueHolder
{
	int value, max, min;
public:
	ValueHolder(int value, int min, int max);
	void Add(int value);
	void Substract(int value);
	int GetValue();
};
ValueHolder::ValueHolder(int value, int min, int max)
{
	this->value = value;
	this->min = min;
	this->max = max;
}
void ValueHolder::Add(int value)
{
	if (this->value + value > max)
		throw OutOfRangeExeption("Result value is greater than allowed maximum");
	this->value += value;
}
void ValueHolder::Substract(int value)
{
	if (this->value - value < min)
		throw OutOfRangeExeption("Result value is lower than allowed minimum");
	this->value -= value;
}
int ValueHolder::GetValue()
{
	return value;
}
int main()
{
	int value, min, max;
	cout << "Input {value}, {minValue}, {maxValue} in the same order "<<endl;
	cin >> value >> min >> max;
	ValueHolder value1(value, min, max);
	cout << "Input {value}, {minValue}, {maxValue} in the same order " << endl;
	cin >> value >> min >> max;
	ValueHolder value2(value, min, max);
	cout << "Input value to add" << endl;
	cin >> value;
	try {
		
		value1.Add(value);
	}
	catch (OutOfRangeExeption &exp)
	{
		cout << exp.Message() << endl;
	}
	try {

		value2.Add(value);
	}
	catch (OutOfRangeExeption &exp)
	{
		cout << exp.Message() << endl;
	}
	cout << "input value to substract" << endl;
	cin >> value;
	try {

		value1.Substract(value);
	}
	catch (OutOfRangeExeption &exp)
	{
		cout << exp.Message() << endl;
	}
	try {

		value2.Substract(value);
	}
	catch (OutOfRangeExeption &exp)
	{
		cout << exp.Message() << endl;
	}
	cout << value1.GetValue() << endl << value2.GetValue() << endl;
	return 0;
}