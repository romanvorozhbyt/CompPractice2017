#include "string"
#include "iostream"
#include "vector"
using namespace std;

class Matrix {
	vector <vector<int>> matrix;
	const int dimy = 0;
	const int dimx = 0;
public:
	Matrix(int const dimY = 1, int dimX = 1, int value = 0) :dimx(dimX), dimy(dimY) {

		for (int i = 0; i < dimY; i++) {
			matrix.insert(matrix.end(), vector <int>(dimX));
			for (int j = 0; j < dimX; ++j)
				matrix[i][j] = value;
		}
	}
	Matrix operator+(int value) {
		if (value == NULL)
			throw string("empty value");
		Matrix n(dimy, dimy);
		for (int i = 0; i < dimy; i++)
		{
			for (int j = 0; j < dimx; j++) {
				n.matrix[i][j] = matrix[i][j] + value;
			}

		}
		return n;
	}
	Matrix operator-(int value) {
		if (value == NULL)
			throw string("empty value");
		Matrix n(dimy, dimy);
		for (int i = 0; i < dimy; i++)
		{
			for (int j = 0; j < dimx; j++) {
				n.matrix[i][j] = matrix[i][j] - value;
			}

		}
		return n;
	}

	Matrix operator*(int value) {
		if (value == NULL)
			throw string("empty value");
		Matrix result(dimy, dimy);
		for (int i = 0; i < dimy; i++)
		{
			for (int j = 0; j < dimx; j++) {
				result.matrix[i][j] = matrix[i][j] * value;
			}

		}
		return result;
	}
	Matrix operator+(Matrix matr) {
		if (matr.dimx != dimx || matr.dimy != dimy)
			throw string("Matrixs must be the same size.\n");
		Matrix result(dimy, dimy);
		for (int i = 0; i < dimy; i++)
		{
			for (int j = 0; j < dimx; j++) 
			{
				result.matrix[i][j] = this->matrix[i][j] + matr.matrix[i][j];
			}
		}
		return result;
	}
	Matrix operator-(Matrix matr) {
		if (matr.dimx != dimx || matr.dimy != dimy)
			throw string("Matrixs must be the same size.\n");
		Matrix result(dimy, dimy);
		for (int i = 0; i < dimy; i++)
		{

			for (int j = 0; j < dimx; j++) {
				result.matrix[i][j] = this->matrix[i][j] - matr.matrix[i][j];
			}

		}
		return result;
	}
	Matrix operator*(Matrix matr) {
		if (dimy != matr.dimx)
			throw string("Matrixs must be the same size.\n");
		Matrix result(dimy, matr.dimy);
		for (int i = 0; i < dimy; i++)
		{
			for (int j = 0; j < matr.dimx; j++)
			{
				result.matrix[i][j] = this->matrix[j][i] * matr.matrix[i][j];
			}

		}
		return result;
	}
	void operator=(Matrix c) {

		Matrix result(dimy, dimy);
		for (int i = 0; i < dimy; i++)
			for (int j = 0; j < dimx; j++) {
				this->matrix[i][j] = c.matrix[i][j];
			}
	
	}


	void print() {
		for (int i = 0; i < this->dimy; i++)
		{
			for (int j = 0; j < this->dimx; j++) {
				cout << this->matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	int x, y;
	cout << "Matrix A:" << endl;
	Matrix a(2, 2, 1);
	a.print();
	cout << "Matrix B:" << endl;
	Matrix b(2, 2, 3);
	b.print();
	cout << "Matrix A + 1:" << endl;
	try 
	{ 
		a = (a + 1); 
		a.print(); 
	}
	catch (string e) 
	{
		cout << e << endl;
	}

	cout << "Matrix A * 2:" << endl;
	try {
		a = a * 2;
		a.print();
	}
	catch (string e)
	{
		cout << e<<endl;
	}

	cout << "Matrix A - 1:" << endl;
	try { 
		a = (a - 1);
		a.print();
	}
	catch (string e) { 
		cout << e;
	}
	cout << "Matrix A + Matrix B:" << endl;
	try { 
		(a + b).print(); 
	}
	catch (string e) 
	{
		cout << e << endl;
	}
	cout << "Matrix A - Matrix B:" << endl;
	try { 
		(a - b).print();
	}
	catch (string e) { 
		cout << e<<endl;
	}

	cout << "Matrix A * Matrix B:" << endl;
	try {
		(a * b).print();
	}
	catch (string e) 
	{ 
		cout << e<<endl;
	}
	cout << "Matrix A:" << endl;
	Matrix aa(2, 2, 1);
	aa.print();
	cout << "Matrix C:" << endl;
	Matrix c(2, 3, 3);
	c.print();
	cout << "Matrix A + Matrix C:" << endl;
	try { 
		(aa + c).print();
	}
	catch (string e) {
		cout << e;
	}

	cout << "Matrix A - Matrix C:" << endl;
	try {
		(aa - c).print(); 
	}
	catch (string e) 
	{
		cout << e<<endl;
	}

	cout << "Matrix A * Matrix C:" << endl;
	try { 
		(aa * c).print();
	}
	catch (string e) 
	{ 
		cout << e<<endl;
	}
	return 0;
}