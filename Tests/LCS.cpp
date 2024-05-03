#include<iostream>
#include<vector>
#include<string>

using namespace std;

int printLCS(string X, vector<vector<char>> CMAT,int M,int N) {
	//cout << X << ":(" << CMAT.size() << "X" << CMAT[0].size() << ")-" << M << ":" << N << endl;
	if (M == 0 || N == 0) {
		return 0;
	}

	

	if (CMAT[M][N] == 'D') {
		//cout << "GOING x" << endl;
		printLCS(X, CMAT, M - 1, N - 1);
		//cout << "GOING OUT x" << endl;
		cout << X[M-1];
	}
	else if (CMAT[M][N] == 'U') {
		//cout << "GOING xx" << endl;
		printLCS(X, CMAT, M - 1, N);
		//cout << "GOING OUT xx" << endl;
	}
	else if (CMAT[M][N] == 'L') {
		//cout << "GOING xxx" << endl;
		printLCS(X, CMAT, M, N - 1);
		//cout << "GOING OUT xxx" << endl;
	}

}

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
			else{
				CHAR_MAT[i][j] = 'L';
				INT_MAT[i][j] = INT_MAT[i][j - 1];
			}
			//cout << INT_MAT[i][j] << ":" << CHAR_MAT[i][j] << "\t";
		}
		//cout << endl;
	}

	for (int i = 0; i < INT_MAT.size(); i++) {
		for (int j = 0; j < INT_MAT[0].size(); j++) {
			cout << INT_MAT[i][j] << ":" << CHAR_MAT[i][j] << "\t";
		}
		cout << endl;
	}

	printLCS(MAIN_STR,CHAR_MAT,CHAR_MAT.size()-1,CHAR_MAT[0].size()-1);

	//cout << MAIN_STR << "," << AUX_STR << endl;
}