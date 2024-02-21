#include<iostream>

using namespace std;

int main() {

	int n,Max = INT_MIN, Min = INT_MAX;;
	cout << "Number of Elements : ";
	cin >> n;
	int* arr= new int[n];
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " Value : ";
		cin >> arr[i];
		if (arr[i] < Min) {
			Min = arr[i];
		}
		else if (arr[i] > Max) {
			Max = arr[i];
		}
	}

	cout << "MINIMUM VALUE OF THE ARRAY : " << Min << endl;
	cout << "MAXIMUM VALUE OF THE ARRAY : " << Max << endl;

	delete arr;
	return 0;
}