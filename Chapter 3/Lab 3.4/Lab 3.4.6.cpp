#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n){
	if(n==1)
		return false;

	for(int i=2; i*i<=n; i++){

		if(n%i==0)
			return false;
		}

	return true;
	}
int main(void) {
for(int i = 0; i <= 21; i++)
if(isPrime(i))
cout << i << " ";
cout << endl;
return 0;
}
