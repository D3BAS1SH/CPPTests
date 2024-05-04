#include<iostream>

using namespace std;

int main() {
	int Num;
	cout << "NUMBR : ";
	cin >> Num;
	long Facto=1;
	for (int i = Num; i >= 2; i--) {
		Facto *= i;
	}
	cout << "Factorial : " << Facto << endl;
}