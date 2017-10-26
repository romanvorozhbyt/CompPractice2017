#include <iostream>; 
using namespace std;
int main(void) {
int vector[] = { 3, -5, 7, 10, -44, 14, 5, 2, -1 };
int n = sizeof(vector) / sizeof(vector[0]);
int *pointer1, *pointer2;
pointer1 = vector;
pointer2 = vector;
pointer2++;
for (int i = 0; i< n-1 ; i++)
{
	if(*pointer1>*pointer2)
	{
		pointer1=pointer2;
	}
	pointer2++;
}
cout<< *pointer1;
return 0;
}
