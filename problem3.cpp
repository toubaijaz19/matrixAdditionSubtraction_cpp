#include<iostream>
using namespace std;
class Matrix {
	int** ptr;
	int rows;
	int cols;
public:
	int count = 0;
public:
	//default constructor
	Matrix()
	{
		rows = 2;
		cols = 2;
		ptr = new int* [rows];
		for (int i = 0; i < rows; i++)
			ptr[i] = new int[cols];
	}
	//overloaded constructor
	Matrix(int r, int c)
	{
		rows = r;
		cols = c;
		ptr = new int* [rows];
		for (int i = 0; i < rows; i++)
			ptr[i] = new int[cols];
	}
	//add operator
	Matrix operator+(Matrix obj)
	{
		Matrix temp(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				temp.ptr[i][j] = ptr[i][j] + obj.ptr[i][j];
			}
		}
		return temp;
	}
	//subtract operator
	Matrix operator-(Matrix obj)
	{
		Matrix temp(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				temp.ptr[i][j] = ptr[i][j] - obj.ptr[i][j];
			}
		}
		return temp;
	}
	//input
	void Input()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cin >> ptr[i][j];
				count++;
			}
		}
	}
	//Print Matrix
	void PrintMatrix()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << ptr[i][j] << "  ";
			}
			cout << endl;
		}
	}
	//destructor
	~Matrix()
	{
		for (int i = 0; i < rows; i++)
			delete[] ptr[i];
		delete[] ptr;
	}
};
int main()
{

	Matrix A(3, 3), B(3, 3), C, D;
	cout << "Enter elements of the Matrix A : " << endl;
	A.Input();
	cout << endl;
	A.PrintMatrix();
	cout << "Enter elements of the Matrix B : " << endl;
	B.Input();
	cout << endl;
	B.PrintMatrix();
	cout << endl << endl;
	//check condition for matrices size
	if (A.count == B.count)
	{
		cout << "After Addition of Matrix A and Matrix B : " << endl;
		cout << "Resultant Matrix : " << endl;
		C = A + B;
		C.PrintMatrix();

		cout << "After Subtraction of Matrix B from Matrix A : " << endl;
		cout << "Resultant Matrix : " << endl;
		D = A - B;
		D.PrintMatrix();
	}
	else
	{
		cout << "Ops!! We can't perform Addition or Subtraction, Because Matrix A and B having different sizes." << endl;
	}
	system("pause");
	return 0;
}
