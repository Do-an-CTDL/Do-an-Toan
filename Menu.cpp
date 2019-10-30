#include "Matrix.h"
#include "KarnaughMap.h"
#include "Menu.h"
#include <Windows.h>


void Menu::ZoomConsole()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

}

void Menu::_Menu_vector() {

	cout << space << " ______________________________________________" << endl;
	cout << space << "| STT |" << setw(23) << "CHUC NANG" << setw(18) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  0  | Thoat khoi chuong trinh" << setw(17) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  1  | Quay ve menu chinh" << setw(22) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  2  | Tao mot vector moi " << setw(21) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  3  | In vector ra man hinh" << setw(19) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  4  | Cong hai vector" << setw(25) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  5  | Nhan vector voi 1 so alpha" << setw(14) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << endl << space << "Lua chon cua ban: ";
}

void Menu::_Menu_matrix() {

	cout << space << " ______________________________________________" << endl;
	cout << space << "| STT |" << setw(23) << "CHUC NANG" << setw(18) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  0  | Thoat khoi chuong trinh" << setw(17) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  1  | Quay ve menu chinh" << setw(22) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  2  | Tao mot ma tran moi " << setw(20) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  3  | In ma tran ra man hinh" << setw(18) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  4  | Tim dinh thuc cua ma tran" << setw(15) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  5  | Tim ma tran nghich dao" << setw(18) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  6  | Nhan hai ma tran" << setw(24) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  7  | Tim hang cua ma tran" << setw(20) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  8  | Giai he phuong trinh tuyen tinh" << setw(9) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << endl << space << "Lua chon cua ban: ";
}

void Menu::_Menu_Bool() {

	cout << space << " ______________________________________________" << endl;
	cout << space << "| STT |" << setw(23) << "CHUC NANG" << setw(18) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  0  | Thoat khoi chuong trinh" << setw(17) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  1  | Quay ve menu chinh" << setw(22) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  2  | Tim da thuc toi tieu " << setw(19) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << endl << space << "Lua chon cua ban: ";
}

void Menu::_Menu() {
	cout << endl << endl << endl;
	cout << space << "               CHUONG TRINH TINH TOAN      " << endl << endl;
	cout << space << " ______________________________________________" << endl;
	cout << space << "| STT |" << setw(23) << "CHUC NANG" << setw(18) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  0  | Thoat khoi chuong trinh" << setw(17) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  1  | Lam viec voi vector " << setw(20) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  2  | Lam viec voi ma tran" << setw(20) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << space << "|  3  | Lam viec voi ham bool" << setw(19) << "|" << endl;
	cout << space << "|_____|________________________________________|" << endl;
	cout << endl << space << "Lua chon cua ban: ";
}

void Menu::Select() {

	_Menu();
	int _choice_main;
	cin >> _choice_main;
	
	while (_choice_main != 0) {
		switch (_choice_main) {

		case 1: {
			
			system("cls");
			cout << endl << endl << endl;
			_Menu_vector();

		begin:

			int _choice_vector;
			fflush(stdin);
			cin >> _choice_vector;

			if (_choice_vector == 3) {
				cout << space << "Ban chua nhap vector\n";
				cout << space << "Moi chon thao tac tiep theo: ";
				goto begin;
			}
			if (_choice_vector == 1) {
				
				break;
			}

			Matrix vector1;

			while (_choice_vector != 1) {

				if (_choice_vector == 0) {
					system("cls");
					cout << "\n\n\n\n\n\n";
					cout << space << "            TAM BIET VA HEN GAP LAI" << endl;
					cout << "\n\n\n\n\n\n";
					Sleep(3000);
					exit(0);
				}

				switch (_choice_vector) {
				
				case 2: {
					cout << endl;
					cout << endl << space << "Luu y vector nay se duoc chon lam vector goc trong suot chuong trinh";
					cout << endl << space << "Neu ban muon thay doi vector goc, hay chon thao tac nay mot lan nua\n";
					cout << endl;

					cout << space << "Nhap vector:\n";
					vector1.InputVector();
					break;
				}

				case 3: {
					if (vector1.GetCol() == 0)
						cout << space << "Ban chua nhap vector\n";
					else {
						cout << space << "Vector la:";
						vector1.OutputVector();
					}
					break;
				}

				case 4: {
					Matrix vector2;

					if (vector1.GetCol() == 0) {
						cout << space << "Ban chua tao mot vector lam goc" << endl;
						cout << space << "Hay chon chuc nang 2 de tao vector lam goc" << endl;
						break;
					}

					cout << space << "Nhap vector thu 2\n";
					vector2.InputVector();

					if (vector1.GetCol() != vector2.GetCol()) {
						cout << endl;
						cout << space << "Hai vector phai co cung so chieu" << endl;
					}
					else {
						Matrix tmp3 = vector1 + vector2;
						
						cout << endl;
						cout << space << "Ket qua la: " << endl;
						cout << tmp3;
					}

					break;
				}

				case 5: {

					if (vector1.GetCol() == 0) {
						cout << space << "Ban chua tao mot vector lam goc" << endl;
						cout << space << "Hay chon chuc nang 2 de tao vector lam goc" << endl;
						break;
					}

					int alpha;

					cout << space << "Nhap he so alpha: ";
					cin >> alpha;
					while (alpha == 0) {
						cout << space << "Alpha phai khac 0. Moi nhap lai: ";
						cin >> alpha;
					}

					Matrix tmp2 = vector1 * alpha;
					
					cout << endl << endl;
					cout << space << "Ket qua cua phep nhan: "  << endl;
					cout << tmp2;

					break;
				}

				default: {
					cout << space << "Khong co chuc nang nay" << endl;
					break;
				}
				}

				cout << endl << space << "Moi chon thao tac tiep theo: ";
				fflush(stdin);
				cin >> _choice_vector;
			}

			break;
		}

		case 2: {
			system("cls");
			cout << endl << endl << endl;
			_Menu_matrix();

			begin1:
			int _choice_matrix;
			fflush(stdin);
			cin >> _choice_matrix;

			if (_choice_matrix == 3) {
				cout << space << "Ban chua nhap vector\n";
				cout << space << "Moi chon thao tac tiep theo: ";
				goto begin1;
			}

			if (_choice_matrix == 1) {

				break;
			}


			Matrix Arr;

			while (_choice_matrix != 1) {
				if (_choice_matrix == 0) {
					system("cls");
					cout << "\n\n\n\n\n\n";
					cout << space << "            TAM BIET VA HEN GAP LAI" << endl;
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					Sleep(3000);
					exit(0);
				}

				switch (_choice_matrix) {

				case 2: {
					cout << endl;
					cout << endl << space << "Luu y ma tran nay se duoc chon lam ma tran goc trong suot chuong trinh";
					cout << endl << space << "Neu ban muon thay doi ma tran goc, hay chon thao tac nay mot lan nua\n";
					cout << endl;
					Arr.InputMatrix();
					break;
				}

				case 3: {
					if (Arr.GetCol() == 0 && Arr.GetRow() == 0)
						cout << space << "Ban chua nhap ma tran\n";
					else
				  		cout << Arr;
					break;
				}

				case 4: {

					if (Arr.GetCol() == 0 && Arr.GetRow() == 0) {
						cout << space << "Ban chua nhap ma tran lam goc" << endl;
						cout << space << "Hay chon chuc nang 2 de tao ma tran lam goc" << endl;
						break;
					}

					while (Arr.GetRow()!= Arr.GetCol()) {
						cout << space << "De tim dinh thuc thi phai nhap ma tran vuong\n";
						cout << "Moi nhap lai ma tran:";
						Arr.InputMatrix();
					}
					cout << endl;
					cout << space << "Ket qua la: " << Arr.Determinant() << endl;
					break;
				}

				case 5: {

					if (Arr.GetCol() == 0 && Arr.GetRow() == 0) {
						cout << space << "Ban chua nhap ma tran lam goc" << endl;
						cout << space << "Hay chon chuc nang 2 de tao ma tran lam goc" << endl;
						break;
					}

					while (Arr.GetRow() != Arr.GetCol()) {
						cout << space << "De tim ma tran nghich dao thi phai nhap ma tran vuong\n";
						cout << "Moi nhap lai ma tran" << endl;
						Arr.InputMatrix();
					}

					if (Arr.Determinant()) {
						Matrix tmp2 = Arr.InversibleMatrix();
						
						cout << endl << space << "Ma tran kha nghich la" << endl;
						cout << Arr;
					}
					else {
						cout << space << "Ma tran nhap vao khong kha nghich nen khong tim duoc ma tran nghich dao" << endl;
					}
					break;
				}

				case 6: {

					if (Arr.GetCol() == 0 && Arr.GetRow() == 0) {
						cout << space << "Ban chua nhap ma tran lam goc" << endl;
						cout << space << "Hay chon chuc nang 2 de tao ma tran lam goc" << endl;
						break;
					}

					Matrix Arr2;
					cout  << space << "Nhap ma tran thu 2" << endl << endl;
					Arr2.InputMatrix();

					while (Arr.GetCol() != Arr2.GetRow()) {
						cout << space << "So cot cua ma tran 1 phai bang voi so dong cua ma tran 2" << endl;
						cout << space << "Moi nhap lai ma tran 2" << endl;
						Arr2.InputMatrix();
					}


					Matrix _tmp_3 = Arr.Multiply(Arr2);
					
					cout << endl << space << "Ket qua la" << endl;
					cout <<  _tmp_3;

					break;
				}

				case 7: {

					if (Arr.GetCol() == 0 && Arr.GetRow() == 0) {
						cout << space << "Ban chua nhap ma tran lam goc" << endl;
						cout << space << "Hay chon chuc nang 2 de tao ma tran lam goc" << endl;
						break;
					}

					cout << space << "Hang cua ma tran la: " << Arr.Rank() << endl;

					break;
				}

				case 8: {

					Matrix _tmp;
					cout << endl << space;
					cout << "Hay nhap ma tran mo rong cua he phuong trinh" << endl;		

					_tmp.InputMatrix();
					_tmp.SystemOfLinearEquations();
					break;
				}

				default: {
					cout << space << "Khong co chuc nang nay" << endl;
					break;
				}
				}

				cout << endl << space << "Moi chon thao tac tiep theo: ";
				fflush(stdin);
				cin >> _choice_matrix;
			}
			break;
		}

		case 3: {
			system("cls");
			cout << endl << endl << endl;
			_Menu_Bool();

			int _choice_bool;
			fflush(stdin);
			cin >> _choice_bool;

			while (_choice_bool != 1) {
				if (_choice_bool == 0) {
					system("cls");
					cout << "\n\n\n\n\n\n";
					cout << space << "            TAM BIET VA HEN GAP LAI" << endl;
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					Sleep(3000);
					exit(0);
				}

				switch (_choice_bool) {

				case 2: {
					BoolFunction tmp;
					cout << endl;
					cout << space;
					cout << "LUU Y" << endl;
					cout << space << "  + Nhap theo thu tu chu cai tang dan" << endl;
					cout << space << "  + Bien a se co phu dinh la a'" << endl;
					cout << endl << space;
					tmp.Input();
					cout << space;
					tmp.Print();
					cout << endl;
					break;
				}

				default: {
					cout << space << "Khong co chuc nang nay" << endl;
					break;
				}
				}
				
				cout << endl << space << "Moi chon thao tac tiep theo: ";
				fflush(stdin);
				cin >> _choice_bool;
			}
			break;
		}
		
		default: {
			cout << space << "Khong co chuc nang nay" << endl;
			break;
		}
		}

		cout << endl;
		system("cls");
		cout << endl << endl << endl;
		_Menu();
		fflush(stdin);
		cin >> _choice_main;
	}

	cout << endl;
	system("cls");
	cout << "\n\n\n\n\n\n";
	cout << space << "            TAM BIET VA HEN GAP LAI" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	Sleep(3000);
	exit(0);
}


