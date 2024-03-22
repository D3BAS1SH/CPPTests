#include<iostream>

using namespace std;

void MergeSort(int A,int LeftI,int RightI) {
	
}

void printArray(int A[], int S) {
	for (int i = 0; i < S; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}

int main() {
	int ARR[] = { 50,12,5,13 };
	int size = sizeof(ARR) / sizeof(ARR[0]);
	printArray(ARR, size);
	return 0;
}