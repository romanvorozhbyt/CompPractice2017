#include <iostream>
using namespace std;
int main(void) {
int c0;
cout << "Enter c0 (non-zero and non-negative)";
cin >> c0;
int steps=0;
while(c0!=1)
{
	if(c0%2==0)
	{
		c0/=2;
	} else if (c0%2==1)
	{
		c0= 3*c0+1;
	}
	steps++;
	cout << c0<<endl;
}
cout << "Steps: "<< steps;
return 0;
}
