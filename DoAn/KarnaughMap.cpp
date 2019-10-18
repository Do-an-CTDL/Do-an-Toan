#include "KarnaughMap.h"

Map::Map() {

	_numVar = 0;
	_n = 0;
	_ceil = NULL;
	_hamBool = "\0";
}

Map::Map(int n) {

	_ceil = new int[_n = n];
}

Map::Map(const Map& a) {

	_ceil = new int[_n = a._n];

	for (int i = 0; i < _n; i++) {
		_ceil[i] = a._ceil[i];
	}

}



void Map::Input() {

	fstream f("input.txt", ios::in);

	getline(f, _hamBool);

	//Dem so bien co trong ham
	for (int i = 0; i < _hamBool.size(); i++) {
		
		int flag = 0;
		if (_hamBool[i] >= 'a' && _hamBool[i] <= 'z' || _hamBool[i] >= 'A' && _hamBool[i] < 'Z') {
			
			char c = _hamBool[i] < 97 ? _hamBool[i] + 'a' - 'A' : _hamBool[i];
			for (int j = 0; j < _tenBien.size(); j++)
				if (_tenBien[j] == c)
					flag = 1;

		}

		//Neu bien chua ton tai thi them bien vao
		if (!flag && _hamBool[i] >= 'a' && _hamBool[i] <= 'z' || _hamBool[i] >= 'A' && _hamBool[i] < 'Z') 
			_tenBien.push_back(_hamBool[i]);
	}

	//So bien se bang kich thuoc cua cac bien khac nhau
	_numVar = _tenBien.size();

	//Sap xep lai ten bien
	sort(_tenBien.begin(), _tenBien.end());

}


//Tim vi tri cua te bao con tren ma nhi phan
vector <int> Map::SearchLocation() {
	
	
	int row = pow(2, _numVar);
	int col = _numVar;

	//ham xac nhan cac te bao con nam o vi tri nao
	bool* teBao = new bool[row];

	for (int i = 0; i < row; i++)
		teBao[i] = 0;
	//Ham chua ma nhi phan tu 0 -> 2^n
	int** Binary = new int*[row];

	for (int i = 0; i < row; i++)
		Binary[i] = new int[col];

	//Chuyen doi nhi phan
	for (int i = 0; i < row; i++) {
		
		int tmp = i;
		for (int j = col - 1; j >= 0; j--) {

			Binary[i][j] = tmp % 2;
			tmp /= 2;
		}
	}

	
	for (int i = 0; i < row; i++) {

		bool flag = 0;
		bool flagCell = 1; //gia su te bao do nam trong vi tri i

		for (int j = 0; j < _hamBool.size(); j++) {

		
			if (_hamBool[j] >= 'a' && _hamBool[j] <= 'z' || _hamBool[j] >= 'A' && _hamBool[j] < 'Z') {

				//gia su ban dau bien do la dung
				bool var = 1;

				int pos = _hamBool[j] - _tenBien[0];
				
				if ( _hamBool[j + 1] == 39) { //dau '
					j++;
					var = 0;
				}

				flagCell = flagCell & (var == Binary[i][pos]);
			}
			else
				if (_hamBool[j] == '+' && flag == 0) {
					
					teBao[i] = flagCell;
					flagCell = 1;
					flag = 1;
				}
				else
					//Neu da co roi
					if (_hamBool[j] == '+' && flag) {

						teBao[i] = teBao[i] | flagCell;
						flagCell = 1;
					}
		}
		teBao[i] = teBao[i] | flagCell;
	}

	vector <int> teBaoCon;

	//Tim vi tri cua te bao con va gan no vao 1 mang
	for (int i = 0; i < row; i++)
		if (teBao[i]) {
			teBaoCon.push_back(i);
			
		}

	//Xoa bo nho da tao
	delete[] teBao;

	for (int i = 0; i < row; i++)
		delete[] Binary[i];

	delete[] Binary;

	return teBaoCon;
}


Map::Map(int size, Map a, Map b) {

	
	_ceil = new int[_n = size];
	
	for (int i = 0; i < size; i++)
		if (i < a._n)
			_ceil[i] = a._ceil[i];
		else
			_ceil[i] = b._ceil[i - a._n];
	
	
	

	sort(_ceil, _ceil + size); // sort cac te bao lai
	
}


//Chia thanh cac nhom te bao
Group Map::ChiaNhom() {

	//Tao 2 ban sao
	vector<int> teBaoCon = SearchLocation();
	
	int n = teBaoCon.size();
	//sort(teBaoCon, teBaoCon + n);
	
	//Dua vao so luong bit toi da co the co
	//Tao 1 mang 3 chieu voi y nghia: (chieu 1: luu giu so bit 1. chieu 2,3: luu tru cac te bao

	//B1: chia thanh cac nhom phu thuoc vao so luong bit 1
	Group** group = new Group * [_numVar + 1];
	for (int i = 0; i < _numVar + 1; i++)
		group[i] = new Group;

	//Chia ra lam cac nhom tuong ung voi so bit dang co tai vi tri do
	for (int i = 0; i < n; i++)
	{
		Map e(1);
		e._ceil[0] = teBaoCon[i];
		
		//Tim so bit 1 cua te bao con do

		int a = teBaoCon[i];
		int num1 = 0;
		while (a > 0) {
			num1 += a & 1;
			a >>= 1;
		}

		group[num1]->Graft.push_back(e);
	}

	//for (int i = 0; i < _numVar + 1; i++)
	//{
	//	vector<Map> ::iterator it;
	//	for (auto it = group[i]->Graft.begin(); it != group[i]->Graft.end(); it++)
	//	{
	//		cout << i << ": ";
	//		for (int j = 0; j < it->_n; j++)
	//			cout << it->_ceil[j] << " ";
	//		cout << endl;
	//	}
	//	cout << endl;
	//}

	//B2: Chia thanh cac nhom nho hon phu thuoc vao so luong bit khac nhau
	
	
	
	vector <Group**> saveCell;


	//Co toi da la _numvar + 1 bit 1
	//Nen duyet toi da _numvar + 1 nhom
	//int duyetNhom = 0; duyetNhom < _numVar + 1; duyetNhom++
	for (; ;) {

		saveCell.push_back(group);

		Group** truyVanCell = new Group * [_numVar + 1]; //Mang luu lai cac phan tu o truoc

		for (int i = 0; i < _numVar + 1; i++)
			truyVanCell[i] = new Group;

		bool flag = 0;

		//Duyet tung nhom
		for (int i = 1; i < _numVar + 1; i++) {

			int lenghtLast = group[i - 1]->Graft.size();
			int lenghtNow = group[i]->Graft.size();

			for (int indexLastCell = 0; indexLastCell < lenghtLast; indexLastCell++) {
				//for (int j = group[i - 1]->Graft[lenghtLast]; j < group[i - 1]->Graft.end; j++) {
				for (int indexNowCell = 0; indexNowCell < lenghtNow; indexNowCell++) {

					/*for (int k = group[i]->Graft.begin; k < group[i]->Graft.end; k++) {*/

					//Kiem tra xem co chung nhom dc k
					//Gia su no  chung 1 nhom
					bool check = 1;
					for (int indexGr = 0; indexGr < group[i - 1]->Graft[indexLastCell]._n; indexGr++) {

						int distance = group[i]->Graft[indexNowCell]._ceil[indexGr] - group[i - 1]->Graft[indexLastCell]._ceil[indexGr];

						//Neu khoang cach do dung bang 2^x( x nguyen) hay = 1 thi gom ve 1 nhom
						if (floor(log2(distance)) != ceil(log2(distance))) {

							check = 0; //khong chung nhom
							break;
						}

					}
					//Xep cung 1 nhom
					if (check) {
						//gia su te bao khong trung vs te bao trc va trong nhom khong co te bao nao trung nhau

						bool check1 = 1, check2 = 1;

						//kiem tra xem 2 te bao dinh noi co trung nhau k

						for (int j = 0; j < group[i - 1]->Graft[indexLastCell]._n; j++)
							for (int k = 0; k < group[i]->Graft[indexNowCell]._n; k++)
								if (group[i - 1]->Graft[indexLastCell]._ceil[j] == group[i]->Graft[indexNowCell]._ceil[k]) {
									check1 = 0;
									break;
								}

						Map Gr(2 * group[i - 1]->Graft[indexLastCell]._n, group[i - 1]->Graft[indexLastCell], group[i]->Graft[indexNowCell]);
						//cout << Gr.ToString() << '\n';

						//bool ktNoi = 1; //xac nhan da noi nhom

						//Kiem tra xem co trung voi nhung nhom trc hay k
						if (truyVanCell[i - 1]->Graft.size() != 0) {

							for (int index = 0; index < truyVanCell[i - 1]->Graft.size(); index++) {
								int count = 0;

								for (int j = 0; j < truyVanCell[i - 1]->Graft[index]._n; j++) {
									if (truyVanCell[i - 1]->Graft[index]._ceil[j] == Gr._ceil[j])
										count++;
								}

								//truyVanCell[i - 1]->Graft.size()
								if (count == Gr._n) {
									check2 = 0;
									break;
								}
							}
						}
						if (check1 == 1 && check2 == 1)
							truyVanCell[i - 1]->Graft.push_back(Gr);
						flag = 1;
					}

					//}
				}
				//}

			}

			/*for (int ix = 0; ix < _numVar + 1; ix++)
			{
				for (int j = 0; j < truyVanCell[ix]->Graft.size(); j++)
				{
					cout << ix << ": ";
					for (int k = 0; k < truyVanCell[ix]->Graft[j]._n; k++)
						cout << truyVanCell[ix]->Graft[j]._ceil[k] << " ";
					cout << endl;
				}
				cout << endl;
			}*/

			
		}

		group = new Group * [_numVar + 1];
		for (int i = 0; i < _numVar + 1; i++)
		{
			group[i] = new Group;

			for (int j = 0; j < truyVanCell[i]->Graft.size(); j++)
				group[i]->Graft.push_back(truyVanCell[i]->Graft[j]);
		}

		/*for (int i = 0; i < _numVar + 1; i++)
		{
			for (int j = 0; j < group[i]->Graft.size(); j++)
			{
				cout << i << ": ";
				for (int k = 0; k < group[i]->Graft[j]._n; k++)
					cout << group[i]->Graft[j]._ceil[k] << " ";
				cout << endl;
			}
			cout << endl;
		}*/

		//Xoa bo nho
		for (int i = 0; i < _numVar + 1; i++)
			if (truyVanCell[i] == NULL)
				delete[] truyVanCell[i];
		delete[] truyVanCell;


		//Th k the them nhom nao nua
		if (!flag)
			break;
		
	}
	
	//cout << endl;
	//for (int ii = 0; ii < saveCell.size(); ii++) {
	//	for (int i = 0; i < _numVar + 1; i++)
	//	{
	//		for (int j = 0; j < saveCell[ii][i]->Graft.size(); j++)
	//		{
	//			cout << i << ": ";
	//			for (int k = 0; k < saveCell[ii][i]->Graft[j]._n; k++)
	//				cout << saveCell[ii][i]->Graft[j]._ceil[k] << " ";
	//			cout << endl;
	//		}
	//		cout << endl;
	//	}
	//}
	//cout << endl;

	//Uu tien bao nhom cac te bao lon nhat
	Group** Tmp = saveCell[saveCell.size() - 1];
	saveCell.pop_back();

	Group baoPhuTeBao;

	for (int i = 0; i < _numVar + 1; i++) {

		for (int j = 0; j < Tmp[i]->Graft.size(); j++)
			baoPhuTeBao.Graft.push_back(Tmp[i]->Graft[j]);
	}

	

	//Kiem tra xem cac nhom nho hon co nam trong te bao lon hon k

	while (saveCell.size()) {
		
		//Lay nhom trc ra
		Tmp = saveCell[saveCell.size() - 1];
		saveCell.pop_back();

		for (int i = 0; i < _numVar + 1; i++) {
			for (int indexNow = 0; indexNow < Tmp[i]->Graft.size(); indexNow++) {
				
				//Gia su dc bao phu rieng biet vs nhau
				int flag = 0;
				for (int indexNode = 0; indexNode < baoPhuTeBao.Graft.size(); indexNode++) {

					int countElement = 0;

					for (int j = 0; j < Tmp[i]->Graft[indexNow]._n; j++)
						for (int k = 0; k < baoPhuTeBao.Graft[indexNode]._n; k++) {

							if (Tmp[i]->Graft[indexNow]._ceil[j] == baoPhuTeBao.Graft[indexNode]._ceil[k])
								countElement++;
						}

					//Truong hop nam hoan toan trong te bao lon hon
					if (countElement == Tmp[i]->Graft[indexNow]._n)
						flag = 1;
				}

				if (!flag) {
					baoPhuTeBao.Graft.push_back(Tmp[i]->Graft[indexNow]);
				}
			}
		}
	}

	/*for (int i = 0; i < baoPhuTeBao.Graft.size(); i++) {

		for (int j = 0; j < baoPhuTeBao.Graft[i]._n; j++) {

			cout << baoPhuTeBao.Graft[i]._ceil[j] << ' ';
		}
		cout << "\n";
	}*/

	//Xoa bo nho da tao
	

	//for (int ii = 0; ii < saveCell.size(); ii++) {
	//	for (int i = 0; i < _numVar + 1; i++)
	//	{
	//		for (int j = 0; j < saveCell[ii][i]->Graft.size(); j++)
	//		{
	//			cout << i << ": ";
	//			for (int k = 0; k < saveCell[ii][i]->Graft[j]._n; k++)
	//				cout << saveCell[ii][i]->Graft[j]._ceil[k] << " ";
	//			cout << endl;
	//		}
	//		cout << endl;
	//	}
	//}
	//

	//Xoa bo nho da cap phat
	teBaoCon.clear();
	//-----------------
	for (int i = 0; i < saveCell.size(); i++) {
		for (int j = 0; j < _numVar + 1; j++) {
			delete[] saveCell[i][j];
		}
		delete saveCell[i];
	}
	saveCell.clear();
	//-----------------
	


	return baoPhuTeBao;
}


Group Map::baoPhuTeBao() {

	Group bigCell = ChiaNhom();

	
	vector <int> locationCell = SearchLocation(); // vi tri ban dau cua cac te bao con 
	
	bool* checkLocationCell = new bool[locationCell.size()];

	//Gia su ban dau tat ca deu dc te bao bao phu
	for (int i = 0; i < locationCell.size(); i++)
		checkLocationCell[i] = 0;


	//Xoa nhung phan tu xuat hien tren 1 lan. uu tien xoa nhom nho hon
	
	//Tao mang phu luu cac nhom co phan tu xuat hien 1 lan
	Group tmpGr;
	int indexGr = 0;
	while (indexGr < locationCell.size()) {
		
		int i = 0;

		Map tmp; //luu 1 nhom tam

		int flag = 1;// gia su te bao do chi xuat hien 1 lan
		int count = 0;
		while (i < bigCell.Graft.size() ) {

			
			for (int j = 0; j < bigCell.Graft[i]._n; j++)
				if (locationCell[indexGr] == bigCell.Graft[i]._ceil[j]) {

					tmp = bigCell.Graft[i];
					count++;
					if (count > 1) {
						flag = 0;
						break;
					}
				}
			//Th xuat hien 2 lan
			i++;
			
		}

		if (count == 1) {
			//Kiem tra xem co trung voi nhom trc hay khong
			//Gia su khong trung nhau
			bool CheckTrung = 1;
			for (int indexTmp = 0; indexTmp < tmpGr.Graft.size(); indexTmp++) {

				//Neu phan tu trong nhom khac nhau thi chac chan khong trung
				if (tmpGr.Graft[indexTmp]._n != tmp._n)
					continue;
				int count1 = 0;

				for (int indexArrGr = 0; indexArrGr < tmpGr.Graft[indexTmp]._n; indexArrGr++)
					if (tmp._ceil[indexArrGr] == tmpGr.Graft[indexTmp]._ceil[indexArrGr])
						count1++;
				if (count1 == tmpGr.Graft[indexTmp]._n)
					CheckTrung = 0;
			}
			if (CheckTrung)
				tmpGr.Graft.push_back(tmp);
		}

		indexGr++;
	}

	
	//for (int iii = 0; iii < bigCell.Graft.size(); iii++) {

	//	for (int jjj = 0; jjj < bigCell.Graft[iii]._n; jjj++) {

	//		cout << bigCell.Graft[iii]._ceil[jjj] << ' ';
	//	}
	//	cout << "\n";
	//}

	//Kiem tra xem con te bao nao chua dc bao phu hay khong
	while (1) {

		for (int i = 0; i < tmpGr.Graft.size(); i++) {
			for (int j = 0; j < tmpGr.Graft[i]._n; j++)

				for (int index = 0; index < locationCell.size(); index++) {
					locationCell[index] = tmpGr.Graft[i]._ceil[j] == locationCell[index] ? -1 : locationCell[index];
				}
		}


		/*for (int i = 0; i < locationCell.size(); i++)
			cout << locationCell[i] << ' ';*/

			//Kiem tra te bao don le dang nam o te bao lon nao
		Group grTrungNhau;
		for (int i = 0; i < bigCell.Graft.size(); i++) {

			//Gia su 
			bool check = 0;
			for (int j = 0; j < bigCell.Graft[i]._n; j++) {

				for (int indexCell = 0; indexCell < locationCell.size(); indexCell++) {

					if (bigCell.Graft[i]._ceil[j] == locationCell[indexCell]) {
						check = 1;
						break;
					}
				}
				if (check) break;
			}

			if (check) grTrungNhau.Graft.push_back(bigCell.Graft[i]);

		}

		/*for (int iii = 0; iii < grTrungNhau.Graft.size(); iii++) {

			for (int jjj = 0; jjj < grTrungNhau.Graft[iii]._n; jjj++) {

				cout << grTrungNhau.Graft[iii]._ceil[jjj] << ' ';
			}
			cout << "\n";
		}*/

		//Ton tai te bao lon bao phu te bao rieng le
		int maxCount = 0;
		int flag1 = 0;
		Map smallCell;

		if (grTrungNhau.Graft.size() > 0) {


			for (int i = 0; i < grTrungNhau.Graft.size(); i++) {

				//Dem xem trong te bao lon do trung vs te bao chua te bao rieng le bao nhieu lan
				//Te bao dc bao phu se la te bao co chua nhieu te bao con chung voi te bao lon dc phu

				int count = 0;
				for (int j = 0; j < grTrungNhau.Graft[i]._n; j++) {

					for (int indexCell = 0; indexCell < locationCell.size(); indexCell++) {
						if (grTrungNhau.Graft[i]._ceil[j] == locationCell[indexCell])
							count++;
					}

					if (maxCount < count) {
						flag1 = 1;
						maxCount = count;
						smallCell = grTrungNhau.Graft[i];
					}
				}

			}
			if (flag1) {
				tmpGr.Graft.push_back(smallCell);
			}
		}
		else
			break;

	}


	/*for (int iii = 0; iii < tmpGr.Graft.size(); iii++) {

		for (int jjj = 0; jjj < tmpGr.Graft[iii]._n; jjj++) {

			cout << tmpGr.Graft[iii]._ceil[jjj] << ' ';
		}
		cout << "\n";
	}*/

	//Huy bo nho da cap phat
	locationCell.clear();

	//-------------------
	delete[] checkLocationCell;

	return tmpGr;
}

void Map::Print() {

	if (_numVar == 1) {
		cout << "Da thuc toi tieu la: ";
		if (_ceil[0] == 0)
			cout << _tenBien[0];
		else
			cout << _tenBien[1];
		return;
	}

	vector <int> locationCell = SearchLocation();

	Group toiTieu = baoPhuTeBao();
	/*for (int i = 0; i < locationCell.size(); i++)
		cout << locationCell[i] << ' ';
	cout << "\n";
	*/
	/*for (int iii = 0; iii < toiTieu.Graft.size(); iii++) {

		for (int jjj = 0; jjj < toiTieu.Graft[iii]._n; jjj++) {

			cout << toiTieu.Graft[iii]._ceil[jjj] << ' ';
		}
		cout << "\n";
	}*/

	cout << "Da thuc toi tieu la: ";

	for (int i = 0; i < toiTieu.Graft.size(); i++) {

		//duyet tu te bao nho len
		int row = toiTieu.Graft[i]._n;
		int col = round(log2(locationCell[locationCell.size() - 1]) + 0.5);

		int** toHop = new int*[row];

		for (int j = 0; j < row; j++)
			toHop[j] = new int[col];

		for (int j = 0; j < row; j++)
			for (int k = 0; k < col; k++)
				toHop[j][k] = 0;


		for (int j = 0; j < toiTieu.Graft[i]._n; j++) {

			int num = toiTieu.Graft[i]._ceil[j];

			int indexCol = col - 1;
			while (num != 0) {
				toHop[j][indexCol--] = num % 2;
				num >>= 1;
			}
		}

		//Luu 3 trang thai cua te bao
		int* res = new int[col];

		/*cout << "\n";
		for (int ii = 0; ii < row; ii++) {
			for (int jj = 0; jj < col; jj++)
				cout << toHop[ii][jj] << ' ';
			cout << "\n";
		}*/

		for (int j = 0; j < col; j++) {

			bool bit1 = 0, bit0 = 0;
			for (int k = 0; k < row; k++)
				if (toHop[k][j])
					bit1 = 1;
				else
					bit0 = 1;
			if (bit1 && bit0)
				res[j] = 0;
			if (!bit1 && bit0)
				res[j] = 1;
			if (bit1 && !bit0)
				res[j] = 2;

		}

		int flag = 0;

		for (int j = 0; j < col; j++) {

			char s = j + _tenBien[0];

			//Th phu dinh
			if (res[j] == 1) {
				flag = 1;
				cout << s << "'";
			}
			else
				if (res[j] == 2) {
					flag = 1;
					cout << s;
				}
		}

		if (flag && i != toiTieu.Graft.size() - 1)
			cout << " + ";


		//Xoa bo nho da cap phat
		for (int j = 0; j < row; j++)
			delete[] toHop[j];
		delete[] toHop;
	}


	//Xoa bo nho da cap phat
	locationCell.clear();
	//-----------------


}
	
Map::~Map() {


	if (_ceil == NULL)
		delete _ceil;
	_hamBool = "\n";
	_numVar = 0;
	_n = 0;
	if (_tenBien.empty())
		_tenBien.clear();
}