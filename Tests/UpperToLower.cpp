#include<iostream>
#include<string>

using namespace std;

int main() {
	string mySTR;
	cout << "Give a String : ";
	getline(cin, mySTR);
	for (int i = 0; i < mySTR.length(); i++) {
		if (mySTR[i] >= 'A' && mySTR[i] <= 'Z') {
			mySTR[i] = mySTR[i] + 32;
		}
	}
	cout << mySTR << endl;
	return 0;
}