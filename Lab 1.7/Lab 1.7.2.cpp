#include <iostream>
#include <iomanip>
using namespace std;
int main(void) {
int x,y;
double epsilom = 0.000001;
bool result;
cout << "Enter first value :";
cin >> x;
cout << "Enter second value :";
cin >> y;
x = double(1/x);
y = double (1/y);
float diff = x-y;
result = (diff < epsilom) && (-diff < epsilom); 
cout << (result ? "equal" : "not equal") << endl;
return 0;
}