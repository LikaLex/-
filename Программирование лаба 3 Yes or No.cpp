#include"stdafx.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

void turn90(vector<vector<bool>>& matrix) {
	auto result = vector<vector<bool>>(matrix[0].size());
	for (auto& v : result)
		v.resize(matrix.size());

	for (int i = 0; i<matrix.size(); i++) {
		for (int j = 0; j<matrix[i].size(); j++) {
			result[j][matrix.size() - 1 - i] = matrix[i][j];
		}
	}

	matrix = result;
}

int main() {
	ifstream fin("in.txt"); // File input

	vector<vector<bool>> hole{//Test values
		{ 1,1,0 },
		{ 1,1,0 },
		{ 1,1,1 },
		{ 1,1,1 }
	};
	vector<vector<bool>> key{//Test values
		{ 1 },
		{ 1 }
	};

	//TODO: INPUT


	int count = 0; //Calculating nulls in hole
	for (auto i : hole)
		for (auto val : i)
			if (!val)
				count++;

	bool flag = false;
	for (unsigned i = 0; i<hole.size(); i++) {//For hole array
		for (unsigned j = 0; j<hole[i].size(); j++) {
			for (unsigned t = 1; t<4; t++) {
				turn90(key); //Turn key 4 times
				if (key.size() + i <= hole.size() && key[0].size() + j <= hole[0].size()) {
					bool _flag = true;//for convenience
					int _count = 0;//for convenience
					for (unsigned ki = 0; ki<key.size(); ki++) {//For key array
						for (unsigned kj = 0; kj<key[ki].size(); kj++) {
							if (!hole[ki + i][kj + j] && !key[ki][kj])//If null is not covered by
							{                                     //one
								_flag = false;
							}
							else if (!hole[ki + i][kj + j])//If it's covered
								_count++;
						}
					}

					if (_flag && _count == count)//If all necessary nulls are covered
						flag = true;
				}
			}
		}
		if (flag)
			break;
	}

	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;


	_getch();
}
