#include <iostream>
using namespace std;
int main(void) {
float pi = 3.14159265359;
float x,y;
cout << "Enter value for x: ";
cin >> x;
float z1,z2;
float x2 = x * x;
z1 = (x2 / (pi * pi * (x2 + 0.5)));
z2 = (1 + (x2/(pi * pi * (x2-0.5)*(x2-0.5))));
y= z1 * z2;

cout << "y = " << y;
return 0;
}
