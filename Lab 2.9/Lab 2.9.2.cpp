#include <iostream>
using namespace std;
int main(void) {
int banknotes[5] = {50, 20, 10, 5, 1};
cout << "Input value that you want to get from ATM\n";
int value;
cin >> value;
while (value !=0)
{
	for (int i = 0; i<5; i++)
	{
		if(value>=banknotes[i])
		{
			value-=banknotes[i];
			cout<<banknotes[i]<<"  ";
			break;
		}
	}
}

return 0;
}
