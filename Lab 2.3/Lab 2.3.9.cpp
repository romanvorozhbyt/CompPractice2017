#include <iostream>
using namespace std;
int main(void) {
	cout<<"input an value greater than 1 and less than 20\n";
	int n;
	long value = 1;
	
	cin >> n;
	if (n<1 && n > 21)
	{
		cout<< "too big value";
	}
	else
	{
		value = (n-1)*(n-1) +1;
		cout << value;
	}
		



return 0;
}