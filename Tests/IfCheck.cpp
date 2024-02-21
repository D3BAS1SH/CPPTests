#include<iostream>

using namespace std;

bool checkT(int v) {
	cout << "Checking" << endl;
	if (v < 10) {
		return true;
	}
	return false;
}

int main() {
	cout << (false && checkT(5)) << endl;
	return 0;
}