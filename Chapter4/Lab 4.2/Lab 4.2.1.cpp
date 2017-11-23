

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
long long Sum(int N)
{
	long long result =0;
	for (int i = 0; i <= N; i++)
	{
		result += i;
	}
	return result;
}
int main()
{
	int N = 100000;
	cout << Sum(N);
	return 0;
}



