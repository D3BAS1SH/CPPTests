#include<iostream>

using namespace std;

void Merge(int A[], int Left, int Mid, int Right) {

	const int L_S = Mid - Left + 1;
	const int R_S = Right - Mid;

	int * LEFT_AR = new int[L_S];
	int* RIGHT_AR = new int[R_S];
	
	for (int i = 0; i < L_S; i++) {
		*(LEFT_AR + i) = A[Left + i];
	}
	for (int j = 0; j < R_S; j++) {
		*(RIGHT_AR + j) = A[Mid + 1 + j];
	}

	int i = 0, j = 0,k=Left;

	while (i < L_S && j < R_S) {
		if (*(LEFT_AR + i) <= *(RIGHT_AR + j)) {
			A[k] = *(LEFT_AR + i);
			i++;
		}
		else {
			A[k] = *(RIGHT_AR + j);
			j++;
		}
		k++;
	}

	while (i < L_S) {
		A[k] = *(LEFT_AR + i);
		i++; k++;
	}

	while (j < R_S) {
		A[k] = *(RIGHT_AR + j);
		j++; k++;
	}

	delete[] LEFT_AR;
	delete[] RIGHT_AR;
}

void MergeSort(int * A, int LeftI, int RightI) {
	if (LeftI < RightI) {
		int MID = LeftI + (RightI - LeftI) / 2;
		MergeSort(A, LeftI, MID);
		MergeSort(A, MID + 1, RightI);
		Merge(A, LeftI, MID, RightI);
	}
}

void printArray(int A[], int S) {
	for (int i = 0; i < S; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}

void ArrayInput(int* A,int s) {
	for (int i = 0; i < s; i++) {
		cout << "VALUE " << i+1 << " : ";
		cin >> *(A + i);
	}
}

int main() {
	int size;
	cout << "Size of the Array : ";
	cin >> size;
	int * ARR = new int[size];
	ArrayInput(ARR,size);
	printArray(ARR, size);
	MergeSort(ARR, 0, size - 1);
	printArray(ARR, size);
	return 0;
}