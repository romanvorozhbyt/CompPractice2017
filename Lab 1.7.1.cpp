#include <iostream>
#include <iomanip>
using namespace std;
int main(void) {
float x,y;
x= 2.3;
y=2.123456;
cout <<x<<endl;
cout << setprecision(5)<<x<<"0"<<endl;
cout <<setprecision(7)<<y<<endl;
cout << setprecision(3)<<y<<endl;
cout << setprecision(1)<<y<<endl	;
return 0;
}