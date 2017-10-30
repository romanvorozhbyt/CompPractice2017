#include <iostream>
using namespace std;
int main(void) {
int vector[] = {3,2,1, 7, 4, 5, 7, 1,2,3};
bool ispalindrome = true;
int n = sizeof(vector) / sizeof(vector[0]);
for(int i = 0; i<n/2; i++)
{
	if(vector[i]!=vector[n-i-1])
	{
		ispalindrome=false;
	}
}
if(ispalindrome)
cout << "It's a palindrome";
else
cout << "It isn't a palindrome";
cout << endl;
return 0;
}
