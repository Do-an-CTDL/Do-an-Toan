#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;
class Map;

struct Group {

	vector <Map> Graft;
	~Group() {
		
		Graft.clear();
	}
};

class Map {
	 string _hamBool;

	int _numVar;	
	int* _ceil;
	int _n;

	vector <char> _tenBien;
	
public:
	Map();
	Map(int);
	Map(const Map&);

	Map(int, Map, Map); //Noi 2 te bao

	string ToString() {
		stringstream w;
		
		for (int i = 0; i < _n; i++)
			w << _ceil[i] << ' ';
		return w.str();
	}

	void Input();

	vector<int> SearchLocation();

	Group ChiaNhom();


	Group baoPhuTeBao();
	//Map& Noi2TeBao(int, Map, Map);

	void Print();

	~Map();
};

