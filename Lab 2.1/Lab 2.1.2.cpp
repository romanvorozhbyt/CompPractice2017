#include <iostream>
using namespace std;
int main(void) {
float grossprice, taxrate, netprice, taxvalue;
cout << "Enter a gross price: ";
cin >> grossprice;
do {
cout << "Enter a tax rate: ";
cin >> taxrate;
} while ((taxrate<0)||(taxrate > 100));
taxvalue = grossprice * taxrate / 100;
netprice = grossprice - taxvalue; 
cout << "Net price: " << netprice << endl;
cout << "Tax value: " << taxvalue << endl;
return 0;
}
