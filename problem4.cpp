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
		cout << "I am default constructor." << endl << endl;
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
	Matrix* A = new Matrix[3];
	cout << "Elements of the First Matrix  : " << endl;
	A[0].Input();
	cout << endl;
	A[0].PrintMatrix();
	cout << "Elements of the 2nd Matrix : " << endl;
	A[1].Input();
	cout << endl;
	A[1].PrintMatrix();
	cout << endl << endl;
	//check condition for matrices size
	if (A[0].count == A[1].count)
	{
		cout << "Addition of First and 2nd Matrix : " << endl;
		//resultant matrix in the A[2].
		A[2] = A[0] + A[1];
		A[2].PrintMatrix();
		cout << endl;
	}
	else
	{
		cout << "Ops!! We can't perform Addition, Because First and 2nd Matrix having different sizes." << endl;
	}
	system("pause");
	return 0;
}