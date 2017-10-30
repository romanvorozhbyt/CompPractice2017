#include <iostream>
using namespace std;
int main(void) {
double matrix[][3] = { { 1, 2, 3 },
{ 2, 1, 2 },
{ 3, 2, 12} };
int side = sizeof(matrix[0]) / sizeof(matrix[0][0]);
bool issymmetric = true;
for (int i = 0; i<side; i++)
{
	for(int j = 0; j<side;j++)
	{
		if(matrix[i][j]!=matrix[j][i])
		{
			issymmetric= false;		
		}
	}
}
if(issymmetric)
cout << "The matrix is symmetric" << endl;
else
cout << "The matrix is not symmetric" << endl;
return 0;
}
