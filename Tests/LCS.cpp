#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	string MAIN_STR, AUX_STR;

	cout << "Main String : ";
	getline(cin, MAIN_STR);
	cout << "Second String : ";
	getline(cin, AUX_STR);

	vector<vector<int>> INT_MAT(MAIN_STR.length()+1,vector<int>(AUX_STR.length()+1));
	vector<vector<char>> CHAR_MAT(MAIN_STR.length() + 1, vector<char>(AUX_STR.length() + 1));

	for (int i = 0; i < INT_MAT.size(); i++) {
		for (int j = 0; j < INT_MAT[0].size(); j++) {
			CHAR_MAT[i][j] = 'Z';
			//cout << INT_MAT[i][j]<<":" << CHAR_MAT[i][j] << "\t";
		}
		//cout << endl;
	}

	for (int i = 1; i < INT_MAT.size(); i++) {
		for (int j = 1; j < INT_MAT[0].size(); j++) {
			if (MAIN_STR[i - 1]== AUX_STR[j - 1]) {
				CHAR_MAT[i][j] = 'D';
				INT_MAT[i][j] = INT_MAT[i - 1][j - 1]+1;
			}
			else if (INT_MAT[i - 1][j] >= INT_MAT[i][j - 1]) {
				CHAR_MAT[i][j] = 'U';
				INT_MAT[i][j] = INT_MAT[i - 1][j];
			}
			else if (INT_MAT[i][j] == INT_MAT[i][j - 1]) {
				CHAR_MAT[i][j] = 'L';
			}
			cout << INT_MAT[i][j] << ":" << CHAR_MAT[i][j] << "\t";
		}
		cout << endl;
	}

	cout << MAIN_STR << "," << AUX_STR << endl;
}