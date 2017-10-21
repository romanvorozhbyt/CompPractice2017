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
		for (int i = 0; i<n; i++)
		{
			if(i==0)
			{
				value = 1;
			}
			else 
			{
				value*=i;
			}
			
		}
		cout << value;
	}
		



return 0;
}