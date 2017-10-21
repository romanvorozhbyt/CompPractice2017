#include <iostream>
using namespace std;
int main(void) {
int year, month, day;
cout << "Enter a year number";
cin >> year;
cout << "Enter a month";
cin >> month;
cout << "Enter a day";
cin >> day;
month-=2;
if (month<0)
{
	month+=12;
	year--;
}
month*=83;
month/=32;
month+=day;
month+=year;
month+=(year/4);
month-=(year/100);
month+=(year/400);
int weekday = month%7;
cout<<weekday;
 
return 0;
}
