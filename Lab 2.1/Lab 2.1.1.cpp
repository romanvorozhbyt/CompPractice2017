#include "iostream"
using namespace std;
int main(void) {
int year;
cout << "Enter a year: ";
cin >> year;
if (year < 1582 )
{
	cout << "Not Grigorian era";
} else if(year%4!= 0)
{
	cout << "common year";
} else if (year%100!=0)
{
	cout<<"leap year";
} else if (year%400!= 0)
{
	cout<<"common year";
} else
{
	cout<< "leap year";
}
return 0;
}
