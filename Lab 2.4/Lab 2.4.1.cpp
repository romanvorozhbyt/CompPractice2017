#include <iostream>
using namespace std;
int main(void) {
	cout<<"input an value greater than 1\n";
	int n;
	int counter = 0;
	cin >> n;
	while (n)
  {
    counter += n & 1;
    n >>= 1;
  	
  }
  cout<< counter;
  
return 0;
}