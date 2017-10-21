#include <iostream>
using namespace std;
int main(void) {
int choise = -1;
double x,y;
do {
	cout << "MENU:\n0 - exit\n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\nYour choice?\n";
	cin>> choise;
	if(choise!=0)
	{
		cout<<"Input two numerics\n"; 
		cin>>x;
		cin>>y;
		switch(choise)
		{
			case 1:
			cout<<"Addition: "<<(x+y);
			break;
			case 2:
			cout<<"subtraction: "<<(x-y);
			break;
			case 3:
			cout<<"multiplication: "<<(x*y);
			break;
			case 4:
			cout<<"division: "<<(x/y);
			break;
			default :
			cout<< "Input number incording to the instruction below";
			break;
		}
	}
	else
	{
		cout << "Good Bye! Thank you for choosing Vorozhbyt Inc.(C)";
	}
	
}while (choise!=0);


return 0;
}
