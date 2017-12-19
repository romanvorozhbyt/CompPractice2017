#include <iostream>

using namespace std;

class Matrix {
private:
	int matrix[2][2];
	int row;
	int col;
	int size;
public:
	Matrix() {
		size = 2;
		row = col = 0;
	}
	friend istream& operator>> (istream& is, Matrix& matrix);
	friend ostream& operator<< (ostream& os, Matrix& matrix);
};

istream& operator>> (istream& is, Matrix& matrix) {
	if (matrix.row == matrix.size && matrix.col == matrix.size)
		throw invalid_argument("Matrix is full");

	if (matrix.col == matrix.size) {
		matrix.col = 0;
		++matrix.row;
	}

	is >> matrix.matrix[matrix.row][matrix.col];
	++matrix.col;

	return is;
}

ostream& operator<< (ostream& os, Matrix& matrix) {
	os << matrix.matrix[0][0] << " " << matrix.matrix[0][1] << endl <<
		matrix.matrix[1][0] << " " << matrix.matrix[1][1];
	return os;
}

int main()
{
	Matrix matrix = Matrix();
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			cout << "Input [" << i << "][" << j << "] element of matrix: ";
			cin >> matrix;
		}
	cout << "Here is your matrix:" << endl << matrix;
	return 0;
}