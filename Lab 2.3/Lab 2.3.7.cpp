#include <iostream>
using namespace std;
int main(void) {
	cout<<"input an value greater than 1 and less than 57\n";
	int n;
	long value = 0;
	long last = 1;
	long prelast= 0;
	cin >> n;
	if (n<1 && n > 57)
	{
		cout<< "too big value";
	}
	else
	{
		for (int i = 0; i<n; i++)
		{
			value =	last + prelast;
			if(i==0)
			{
				prelast = 0;
			}
			else 
			{
				prelast = last;
			}
			last= value;
			
		}
		cout << value;
	}
		



return 0;
}