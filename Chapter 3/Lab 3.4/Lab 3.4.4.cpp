#include <iostream>
using namespace std;

struct Date
{
	int year, month, day;
};
bool isLeap(int year) {
	if (year % 4 != 0 && year % 400 != 0)
		return false;
	else return true;
}
int monthLength(int year, int month) {
	if(!isLeap(year)&&month==2)
        return 28;
    else
        return 28+(month+month/8)%2+2%month+2/month;
}
int dayOfYear(Date date) {
	int sum = 0;
	for(int i=1;i<date.month;i++){
		sum+=monthLength(date.year, i);
	}
	return sum+date.day;
}
int daysBetween(Date d1, Date d2) {
	int dd1=0 , dd2;
	if(d2.year<d1.year)
		return -1;
	for(int i = d1.year; i<d2.year; i++){
		if(isLeap(i))
			dd1+=366;
		else
			dd1+=365;
	}
	dd1+=dayOfYear(d2) - dayOfYear(d1);
	if(dd1<0)
		return -1;
	return dd1;
}

int main(void) {
Date since,till;
cout << "Enter first date (year month day): ";
cin >> since.year >> since.month >> since.day;
cout << "Enter second date (year month day): ";
cin >> till.year >> till.month >> till.day;
cout << daysBetween(since,till) << endl;
return 0;


}
