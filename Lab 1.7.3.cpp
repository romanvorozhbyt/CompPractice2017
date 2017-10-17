#include <iostream>
#include <iomanip>
using namespace std;
int main(void) {
int x1,x2,x3,x4;
do
{
cout<< "Input 4 numbers from 0 to 255 exept first value must be greater than 0\n";
cin >> x1;
cin >> x2;
cin >> x3;
cin >> x4;
} while (((x1<=0)||(x1>255))&&((x2<0)||(x2>255))&&((x3<0)||(x3>255))&&((x4<0)||(x4>255)));
cout<<x1<<"."<<x2<<"."<<x3<<"."<<x4;
return 0;
}