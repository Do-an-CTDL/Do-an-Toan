#include <iostream>
using namespace std;
//---------------------
#define max(a,b) a > b ? a: b



class Matrix {
private:
	string _name;
	int _col, _row;
	float** _matrix;

	
	Matrix operator*(int alpha);

public:
	Matrix();
	Matrix(const Matrix&);
	Matrix(int, int);
	Matrix(int);
	Matrix(int row, int col, float** matrix);
	~Matrix();

	//---------
	float Determinant();
	float Calculate(float**, int, int);
	//---------

	string GetName(); //Get the name of the vector

	void InputVector(); //Input the data of a vector
	void OutputVector(); //Print the data of a vector

	//---------
	void Swap(float*&, float*&);
	void EchelonCompactMatrix(int col = 0);
	int Rank();
	Matrix MatrixTransposition(); //Chuyen vi ma tran
	Matrix MatrixEliminate(int row, int col); //Tim  ma tran loai bo dong i cot j
	Matrix FindAdj(); //Tim ma tran phu hop cua ma tran
	Matrix InversibleMatrix(); //Tim ma tran kha nghich
	//---------

	//-------
	void SystemOfLinearEquations();


	float GetNumArray(int i, int j);
	int GetCol();
	int GetRow();
	float** GetArray();




	friend ostream& operator <<(ostream&, Matrix&);
	void InputMatrix();
	Matrix Multiply(Matrix b); //Nhan hai ma tran cap m x n voi n x p

	Matrix operator + (const Matrix&);

	float& operator[] (int i) {
		return _matrix[0][i];
	}

	//void Tong();
};