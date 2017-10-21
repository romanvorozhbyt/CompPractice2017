#include <iostream>
using namespace std;
int main(void) {
	cout<<"input an value greater than 1 and less than 20\n";
	int value;
	cin >> value;
	if (value<1 && value > 20)
	{
		cout<< "too big value";
	}
	else 
	{
cout << '+';
for(int i = 0; i < value; i++)
cout << '-';
cout << '+' << endl;
for(int i = 0; i < value; i++) {
cout << '|';
for(int j = 0; j < value; j++)
cout << ' ';
cout << '|' << endl;
}
cout << '+';
for(int i = 0; i < value; i++)
cout << '-';
cout << '+' << endl;
}
return 0;
}