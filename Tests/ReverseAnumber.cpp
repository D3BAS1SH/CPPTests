#include<iostream>

using namespace std;

int main() {
	long Num,Rev=0;
	cout << "NUMBER : ";
	cin >> Num;
	while (Num != 0) {
		Rev = (Rev * 10) + Num % 10;
		Num /= 10;
	}
	cout << "Reveresed Number : " << Rev << endl;
	return 0;
}