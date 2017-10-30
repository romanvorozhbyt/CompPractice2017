#include <iostream>
using namespace std;
struct DATE {
	int HH;
	int MM;
};
int main(void) {
	DATE date = {};
cout<< "Input hours\n";
cin>> date.HH;
cout<<"Input minutes\n";
cin>> date.MM;
if (date.HH>24&&date.HH<0&&date.MM>60&&date.MM<0)
{
	cout<<"Hours must be less than 24. Minutes must be less than 60\n";
}
else
{
	int event;
	cin >> event;
	while(event!=0)
	{
		if (event>60)
		{
			date.HH++;
			
			event-=60;
		}
		else 
		{
			if (date.MM+event>60)
			{
				date.MM+=event -60;
				date.HH++;
				event = 0;
			}
			else
			{
				date.MM+=event;
				event=0;
			}
		}
		if(date.HH==24)
		{
				date.HH=0;
		}
	}
	cout<<date.HH<<" : "<<date.MM;
}
return 0;
}
