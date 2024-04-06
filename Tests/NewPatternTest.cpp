#include<iostream>

using namespace std;

int main() {
	//cout << "Hello World" << endl;
	const int Limit = 8;
	int** MyMainArr = new int* [Limit];
	for (int i = 0; i < Limit; i++) {
		*(MyMainArr + i) = new int[i + 1];
	}

	int count = 1;
	for (int i = 0; i < Limit; i++) {
		for (int j = ((i % 2 == 0) ? i : Limit - 1); j != ((i % 2 == 0) ? (Limit) : i - 1); (i%2==0)?(j++):(j--)) {
			*(*(MyMainArr + j) + i) = count;
			count++;
		}
	}

	for (int i = 0; i < Limit; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << *(*(MyMainArr + i) + j) << "\t";
		}
		delete* (MyMainArr + i);
		cout << endl;
	}
	return 0;
}