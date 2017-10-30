#include <iostream>
using namespace std;
struct DATE {
	int HH;
	int MM;
};
int main(void) {
	DATE startTime = {};
	DATE endTime = {};
cout<< "Input hours for the first startTime\n";
cin>> startTime.HH;
cout<<"Input minutes for the first startTime\n";
cin>> startTime.MM;
cout<< "Input hours for the endTime\n";
cin>> endTime.HH;
cout<<"Input minutes for the endTime\n";
cin>> endTime.MM;
if (startTime.HH>24&&startTime.HH<0&&startTime.MM>60&&startTime.MM<0 && endTime.HH>24&&endTime.HH<0&&endTime.MM>60&&endTime.MM<0)
{
	cout<<"Hours must be less than 24. Minutes must be less than 60\n";
}
else
{
	if(startTime.HH>endTime.HH & startTime.MM>endTime.MM)
	{
		cout<<"End time must be later";
	}
	else
	{
		if(endTime.MM-startTime.MM<0)
		{
			endTime.HH--;
			endTime.MM= endTime.MM + 60 - startTime.MM;
			
		}
		else
		{
		endTime.MM-=startTime.MM;
		
		}
		endTime.HH-=startTime.HH;
	}
}
cout << endTime.HH << " : "<< endTime.MM;
return 0;
}
