#include <iostream>
using namespace std;
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
int main(void) {
	for (int yr = 2000; yr < 2002; yr++) {
		for (int mo = 1; mo <= 12; mo++)
			cout << monthLength(yr, mo) << " ";
		cout << endl;
	}
	return 0;
}
