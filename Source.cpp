#include "Matrix.h"

int main() {
	Matrix a(2, 3);
	Matrix b(3, 2);
	a.InputMatrix();
	b.InputMatrix();


	//Determinant condition
	//Muon tinh dinh thuc thi ma tran phai la ma tran vuong
	if (a.GetRow() != a.GetCol()) {
		cout << "Matrix must be square matrix" << endl;
	}
	else {
		cout << a.Determinant() << endl;
	}

	//Inverse condition
	//Muon tim ma tran nghich dao thi ma tran do phai kha nghich truoc
	//Hay noi cach khac la det phai khac 0
	if (a.Determinant() == 0) {
		cout << "Can't find inverse matrix" << endl;
	}
	else {
		Matrix tmp = a.InversibleMatrix();
		cout << tmp;
	}
	
	//Multiply condition
	//Muon nhan ma tran A voi ma tran B thi so cot cua A phai bang voi so dong cua B
	if (a.GetCol() != b.GetRow()) {
		cout << "Can't multiply two matrix together" << endl;
	}
	else {
		Matrix tmp = a.Multiply(b);
		cout << tmp;
	}
	
	
	return 0;
}

