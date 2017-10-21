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
		
		for (int i=0; i<value; i++)
		{
		
			for(int j=0;j<value-i;j++)
			{
				cout << " ";
			}
			cout << "*";
			
			if (i!=value-1)
			{
				for(int j=0;j<i;j++)
				{
					cout << "  ";
				}
			} else 
			{
				for(int j=0;j<i;j++)
				{
					cout << "**";
				}
			}
			if(i!=0)
			{
			cout<<"*"<<endl;
			}
			else
			{
				cout<<endl;
			}
		}
		
}


return 0;
}