#include <iostream>
using namespace std;

int main(void) {
	int k;//power
	cin>> k;
	int value = 1;
	for	(int i = 0; i < k; i++)
	{
		value = value << 1;
	}
	cout<< value;
	return 0;
	
}