#include "Matrix.h"


//Cac ham khoi tao
Matrix::Matrix() {

	_col = 0;
	_row = 0;
	_matrix = NULL;
	_name = "\n";
}


Matrix::Matrix(int col) {

	_col = col;
	_matrix = new float*[_row = 1];

	for (int i = 0; i < _row; i++)
		_matrix[i] = new float[_col];
	_name = "\n";
}


Matrix::Matrix(int row, int col, float** matrix)
{
	_row = row;
	_col = col;
	_matrix = new float* [row];
	for (int i = 0; i < row; i++) {
		_matrix[i] = new float[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			_matrix[i][j] = matrix[i][j];
		}
	}
}


Matrix::Matrix(int row, int col) {

	_matrix = new float* [_row = row];

	_col = col;

	for (int i = 0; i < row; i++) {
		_matrix[i] = new float[col];
	}
}

//---------------

//Ham sao chep 
Matrix::Matrix(const Matrix& Matrix2) {

	//Cap phat
	_matrix = new float* [_row = Matrix2._row];
	_col = Matrix2._col;

	for (int i = 0; i < _row; i++) {
		_matrix[i] = new float[Matrix2._col];
	}

	//gan gia tri
	for (int i = 0; i < _row; i++)
		for (int j = 0; j < _col; j++)
			_matrix[i][j] = Matrix2._matrix[i][j];

}

//Cac ham getter
float** Matrix::GetArray() {

	//Cap phat
	float** tmp = new float* [_row];

	for (int i = 0; i < _row; i++) {
		tmp[i] = new float[_col];
	}

	//gan gia tri
	for (int i = 0; i < _row; i++)
		for (int j = 0; j < _col; j++)
			tmp[i][j] = _matrix[i][j];

	return tmp;
}


float Matrix::GetNumArray(int i, int j) {

	return _matrix[i][j];
}


int Matrix::GetCol() {
	return _col;
}

int Matrix::GetRow() {
	return _row;
}

//----------------------


//ham tim dinh thuc theo dinh nghia (Nguon: Sach dai so tuyen tinh Thay Le Van Luyen)
float Matrix::Calculate(float** a, int _rowTmp, int _colTmp) {

	float res = 0;

	for (int i = 0; i < _colTmp; i++) {

		//Neu ma tran con 2x2 thi dinh thuc bang duong cheo chinh tru duong cheo phu
		if (_rowTmp == 2 && _colTmp == 2)
			return a[0][0] * a[1][1] - a[0][1] * a[1][0];

		//Th ma tran chi co 1x1
		if (_rowTmp == 1 && _colTmp == 1)
			return a[0][0];

		//Tao ma tran phu la ma tran loai di dong 0 va cot i

		//Khoi tao
		float** tmp;
		int _rowTmpNew = _rowTmp - 1;
		int _colTmpNew = _colTmp - 1;
		tmp = new float* [_rowTmpNew];

		for (int j = 0; j < _rowTmpNew; j++)
			tmp[j] = new float[_colTmpNew];


		//gan gia tri
		int _newRow = 0, _newCol = 0;

		for (int row = 1; row < _rowTmp; row++) {
			int col;
			for (col = 0; col < _colTmp; col++) {
				if (col != i) {
					tmp[_newRow][_newCol++] = a[row][col];
				}
			}
			if (col != i) _newRow++;
			_newCol = 0;
		}

		//----------------------

		//Ham de quy theo cong thuc tinh dinh thuc
		res += a[0][i] * Calculate(tmp, _rowTmp - 1, _rowTmp - 1) * ((i) % 2 == 0 ? 1 : -1);


		//Giai phong mang tmp vua cap phat
		for (int row = 0; row < _rowTmpNew; row++)
			delete tmp[row];
		delete[] tmp;
	}

	return res;
}

float Matrix::Determinant() {

	//Tao ma tran tmp de khong mat du lieu
	float** tmp = GetArray();

	//Goi ham tinh dinh thuc
	return Calculate(tmp, _row, _col);

}
//-------------------------
void Matrix::Swap(float*& a, float*& b) {

	float* tmp = a;
	a = b;
	b = tmp;
}


//Tim ma tran bac thang rut gon
void Matrix::EchelonCompactMatrix(int _eliminateCol) {
	int rows = 0, col = 0;


	while (rows < _row && col < _col + _eliminateCol) {


		if (_matrix[rows][col] != 0) {

			//dk - (akj/aij)*di
			//tru cac dong
			float radiusMain = float(1.0 / _matrix[rows][col]);
			//Rut gon lai dong chinh
			for (int i = 0; i < _col; i++) {
				_matrix[rows][i] = radiusMain * _matrix[rows][i];
			}


			//Truy van cac dong phu
			for (int k = 0; k < _row; k++) {

				//He so de tru cac dong
				float radiusExtra = _matrix[k][col];

				for (int minusCol = 0; minusCol < _col; minusCol++) {

					if (rows != k) {
						//Fix loi hinh thi so -0
						_matrix[k][minusCol] = (_matrix[k][minusCol] - radiusExtra * _matrix[rows][minusCol] == 0) ? 0 : _matrix[k][minusCol] - radiusExtra * _matrix[rows][minusCol];
					}


				}
			}


			rows++;
			col++;
		}
		else {
			for (int k = rows; k < _row; k++) {
				if (_matrix[k][col] != 0) {

					Swap(_matrix[k], _matrix[rows]);
					break;
				}
				else {

					col++;
					break;
				}
			}
		}
	}


}

//Ham tim hang ma tran
//Thuat toan Gauss (Nguon: Sach dai so tuyen tinh Thay Le Van Luyen)
int Matrix::Rank()
{

	//Tao lop phu de khong mat du lieu
	Matrix MatrixTmp = *this;

	//B1
	//Tim ma tran bac thang rut gon
	MatrixTmp.EchelonCompactMatrix();


	//B2
	//Tim hang cua ma tran
	//Gia su hang bang so dong
	int rank = _row;

	for (int rows = 0; rows < _row; rows++) {

		//dat co hieu
		bool flag = 0;

		for (int col = 0; col < _col; col++)
			if (MatrixTmp._matrix[rows][col] != 0) {
				flag = 1; //neu co bat ki so nao tren dong khac 0 thi bat co hieu
			}

		if (!flag) rank--;//Neu dong toan 0 thi rank - 1
	}

	return rank;
}

//-----------------------

//Giai He phuong trinh tuyen tinh
void Matrix::SystemOfLinearEquations() {

	//Gan mang phu de khong bi mat du lieu
	Matrix MatrixTmp = *this;


	//B1: Tim ma tran bac thang rut gon
	MatrixTmp.EchelonCompactMatrix(1);

	//B2: Bien luan ma tran
	_col--;
	int rankMatrix = Rank();
	_col++;

	int rankNew = Rank();

	//cout << rank;
	//TH1: pt co 1 nghiem duy nhat rank = n

	if (rankMatrix == _row && rankMatrix == rankNew) {
		cout << "Phuong trinh co 1 nghiem duy nhat: \n";
		for (int i = 0; i < _row; i++) {
			cout << "a" << i + 1 << " = " << MatrixTmp._matrix[i][_col - 1] << "\n";
		}
	}
	else
		if (rankMatrix + 1 == rankNew)
			cout << "Phuong trinh vo nghiem\n";
		else {

			//So bien bang hang cua phan tu
			for (int i = 0; i < rankMatrix; i++) {
				cout << "a" << i + 1 << " = " << MatrixTmp._matrix[i][_col - 1];

				//Ki thuat dat co hieu
				//khi gap phan tu co so thi bat co hieu
				bool flag = 0;

				//Phan tu de ky hieu bien
				int symbol = 1;
				for (int j = 0; j < _col; j++) {
					if (flag) {
						if (MatrixTmp._matrix[i][j] != 0) {
							if (MatrixTmp._matrix[i][j] > 0)
								cout << " + ";
							else
								if (MatrixTmp._matrix[i][j] < 0)
									cout << " - ";
							cout << fabs(MatrixTmp._matrix[i][j]) << "*t" << symbol++;
						}
						//else symbol++;
					}
					else {
						if (MatrixTmp._matrix[i][j] != 0) flag = 1;
					}
				}
				cout << "\n";
			}
		}


}

//Ham xuat
ostream& operator <<(ostream& os, Matrix& MatrixOut) {

	os << "Ma tran sau khi thuc hien phep toan la: \n";

	for (int i = 0; i < MatrixOut._row; i++) {
		for (int j = 0; j < MatrixOut._col; j++)
			os << MatrixOut._matrix[i][j] << ' ';
		os << '\n';
	}

	return os;
}

//Ham nhap
void Matrix::InputMatrix()
{
	for (int i = 0; i < _row; i++) {
		for (int j = 0; j < _col; j++) {
			cin >> _matrix[i][j];
		}
	}
}



Matrix Matrix::MatrixTransposition()
{
	Matrix _Result(_row, _col); //Khoi tao mot ma tran moi co dong va cot giong ma tran cu

	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			_Result._matrix[j][i] = _matrix[i][j];
		}
	}
	return _Result;
}

Matrix Matrix::MatrixEliminate(int row, int col) //row, col la dong, cot bi loai
{
	Matrix _Result(_row - 1, _col - 1);

	/*Phan tu a[i][j] trong ma tran moi se tuong ung
	voi phan tu a[temp_i][temp_j] trong ma tran cu*/

	//Thuat toan
	/* Neu i(j) >= row(col) thì temp_i (temp_j) = i(j) +1
	   Nguoc lai thi temp_i(temp_j) = i(j)  */

	int temp_i;
	int temp_j;

	for (int i = 0; i < _row - 1; i++) {
		for (int j = 0; j < _col - 1; j++) {
			if (i >= row) {
				temp_i = i + 1;
			}
			else {
				temp_i = i;
			}
			if (j >= col) {
				temp_j = j + 1;
			}
			else {
				temp_j = j;
			}
			_Result._matrix[i][j] = _matrix[temp_i][temp_j];
		}
	}
	return _Result;
}

//Tim ma tran phu hop cua ma tran
Matrix Matrix::FindAdj() {
	float** tmp = GetArray();
	//Tao mot Matrix moi de tranh bi mat du lieu
	Matrix _tmp(_row, _col, tmp);
	delete[] tmp;

	Matrix _adj(_row, _col);

	//Thuat toan
	// _adj[i][j] = (-1)^(i+j) * det(A(i|j))

	for (int i = 0; i < _row; i++) {
		for (int j = 0; j < _col; j++) {
			Matrix temp = _tmp.MatrixEliminate(i, j);
			_adj._matrix[i][j] = pow(-1, i + j) * temp.Determinant();
		}
	}

	Matrix _Transform_Adj = _adj.MatrixTransposition();
	return _Transform_Adj;
}



//Tim ma tran kha nghich
Matrix Matrix::InversibleMatrix() {
	float Det = Determinant();
	Matrix temp = FindAdj();
	Matrix _Result = temp * (1 / Det);
	return _Result;
}

Matrix Matrix::Multiply(Matrix b)
{
	Matrix _Result(_row, b._col);
	for (int i = 0; i < _Result._row; i++)
	{
		for (int j = 0; j < _Result._col; j++)
		{
			_Result._matrix[i][j] = 0;
			for (int k = 0; k < _col; k++)
			{
				_Result._matrix[i][j] += _matrix[i][k] * b._matrix[k][j];
			}
		}
	}

	return _Result;
}

//nhan vector vs 1 so
Matrix Matrix::operator*(int alpha) {
	Matrix _Result(_row, _col);
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _row; j++)
		{
			_Result._matrix[i][j] = alpha * _matrix[i][j];
		}
	}
	return _Result;
}


// Cac ham vector

Matrix Matrix::operator + (const Matrix& b)
{

	Matrix _Result(_col);
	if (_col != b._col)
	{
		cout << "Two vectors must have the same quantity of elements" << endl;
		return _Result;
	}
	
	for (int j = 0; j < _row; j++) {
		for (int i = 0; i < _col; i++)
		{
			_Result._matrix[j][i] = _matrix[j][i] + b._matrix[j][i];
		}
	}

	return _Result;
}


//ham nhap vector
void Matrix::InputVector()
{
	cout << "Input the number of elements: ";
	fflush(stdin);
	cin >> _col;
	_matrix = new float*[_col];
	_row = 1;

	for (int i = 0; i < _col; i++)
		_matrix[i] = new float[_row];

	cout << "Please input value: ";
	float temp;
	for (int i = 0; i < _col; i++)
	{
		cin >> temp;
		_matrix[0][i] = temp;
	}
	
}


void Matrix::OutputVector()
{
	cout << " = (" << _matrix[0][0];
	for (int i = 1; i < _col; i++)
	{
		cout << ", " << _matrix[0][i];
	}
	cout << ")" << endl;
}


//Ham huy
Matrix::~Matrix() {
	
	if (_row != 1) {
		for (int i = 0; i < _row; i++)
			delete[] _matrix[i];
	}

	delete[] _matrix;

	_col = 0;
	_row = 0;
}