#include <iostream>
#include <cmath>
using namespace std;
int main(void) {
double vector[] = { 1., 2., 3., 4., 5. };
int n = sizeof(vector) / sizeof(vector[0]);
double ArithmeticMean;
double HarmonicMean;
double GeometricMean=0;
double RootMeanSquare = 0;
for (int i = 0; i< n; i++)
{
	ArithmeticMean+=vector[i]/n;
	HarmonicMean+=1/vector[i];
	GeometricMean*=vector[i];
	RootMeanSquare+=pow(vector[i],2);
}
GeometricMean = pow (GeometricMean, 1/n);
HarmonicMean= n/HarmonicMean;
RootMeanSquare=sqrt(RootMeanSquare/n);
cout << "Arithmetic Mean = " << ArithmeticMean << endl;
cout << "Harmonic Mean = " << HarmonicMean << endl;
cout << "Geometric Mean = " << GeometricMean << endl;
cout << "RootMean Square = " << RootMeanSquare << endl;
cout << endl;
return 0;
}
