#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	unsigned long long a = 2;
	
	for(int i=1;i<n;i++)
	{
		a = a << 1;
	}
	double b =1./a;
	cout<<b;
	return 0;
}