#include "Matrix.h"
#include "KarnaughMap.h"


int main() {
	//int n, m;
	////cin >> n;
	////cin >> m;
	//Matrix a(4,4);
	//
	//a.InputMatrix();
	//cout << a.Determinant() << "\n";
	//
	//a.EchelonCompactMatrix();

	//cout << a;
	//cout << "\n";
	//cout << a.Rank();
	//a.SystemOfLinearEquations();
	////Map a;
	////a.Input();
	//
	///*vector <int> b = a.SearchLocation();

	//for (int i = 0; i < b.size(); i++)
	//	cout << b[i] << ' ';
	//cout << endl;*/
	////a.Print();

	Matrix d, b;
	d.InputVector();
	b.InputVector();
	//Matrix c = a.Cong2Vector(b);
	Matrix c = d + b;
	c.OutputVector();


	system("PAUSE");
	return 0;

}

