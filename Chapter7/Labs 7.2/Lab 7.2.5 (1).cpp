#include <iostream>
#include <string>
using namespace std;
//add your own exception class here

class InvalidOperationExeption {

public:
	string message;
	InvalidOperationExeption(string mess)
	{
		message = mess;
	}

};
class Matrix {
	int **elements;
	int rows, columns;
public:
	
	Matrix(int rows, int columns)
	{
		if (rows <= 0)
			throw InvalidOperationExeption("Rows count can't be less or equal to zero");
		if (columns <= 0)
			throw InvalidOperationExeption("Columns count can't be less or equal to zero ");
		elements = new int*[rows];
		for (int i = 0; i < rows; i++)
		{
			this->elements[i] = new int[columns];
		}
		this->columns = columns;
		this->rows = rows;
		
	}
	void FillCell(int row, int col, int value)
	{
		if (row >= rows || row < 0)
			throw InvalidOperationExeption("Row number must be less than matrix size and greater than 0 ");
		if (col>= columns || col < 0)
			throw InvalidOperationExeption("column number must be less than matrix size and greater than 0 ");
		this->elements[row][col] = value;
	}
	void Add(Matrix *m)
	{
		if (m->columns != this->columns || m->rows != this->rows)
			throw InvalidOperationExeption("You can't add matrixs with different size. Check your input");
		for (int i = 0; i < this->rows; i++)
			for (int j = 0; j < this->columns; j++)
				this->elements[i][j] += m->elements[i][j];
	}
	void Add(int val)
	{
		for (int i = 0; i < this->rows; i++)
			for (int j = 0; j < this->columns; j++)
				this->elements[i][j] += val;

	}
	void Print()
	{
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->columns; j++)
			{
				cout << this->elements[i][j]<<"  ";
			}
			cout << endl;
		}
		cout << endl;

	}

};
Matrix* CreateMatrix()
{
	Matrix* matrix = nullptr;
	int val, rows, cols;
	try {
	cout << "Matrix creation form:"<<endl<<"Input rows number" << endl;
	cin >> rows;
	cout << "Input columns number" << endl;
	cin >> cols;
	if (rows < 0 || cols < 0)
		throw InvalidOperationExeption("row and col count must be positive");
	matrix =  new Matrix(rows, cols);
	
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << "[" << i << "," << j << "] elem: "<<endl;
				cin >> val;
				matrix->FillCell(i, j, val);
			}
		}
	}
	catch (...)
	{
		throw;
	}
	return matrix;

}
int main()
{
	try {
		Matrix *m1 = CreateMatrix();
		Matrix *m2 = CreateMatrix();
		Matrix *m3 = CreateMatrix();
		try {
			m1->Add(1);
			m1->Add(m2);
		}
		catch (InvalidOperationExeption &exp)
		{
			cout << exp.message << endl;
		}
		try {
			m2->Add(m3);
		}
		catch (InvalidOperationExeption &exp)
		{
			cout << exp.message << endl;
		}
		try {
			m3->Add(m1);
		}
		catch (InvalidOperationExeption &exp)
		{
			cout << exp.message << endl;
		}
		m1->Print();
		m2->Print();
		m3->Print();

	}

	catch (InvalidOperationExeption &exp)
	{
		cout << exp.message << endl;
	}
	

	return 0;
}