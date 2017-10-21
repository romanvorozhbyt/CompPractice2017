#include <iostream>
using namespace std;
int main(void) {
int sys;
float m, ft, in;
cin>>sys;
if(sys==0)
{
	
	cin>>m;
	ft=3.28084*m;
	in=(ft-(int)ft)*12;
	cout<<(int)ft<<"'";
	cout<< in<<"''";
	
	}
else 
{
	cin>>ft;
	cin>>in;
	m=ft*0.3048+0.0254*in;
	cout<<m<<"m";
}	
return 0;
}