#include<iostream>

using namespace std;

class BOX {
private:
	int length, breadth, height;
public:
	BOX(int l, int b, int h) :length{ l }, breadth{ b }, height{ h } {
		cout << length << endl;
		cout << breadth << endl;
		cout << height << endl;
	}
	BOX() :length{ 0 }, breadth{ 0 }, height{0} {
		cout << length << endl;
		cout << breadth << endl;
		cout << height << endl;
	}
};

int main() {
	BOX B1(10, 50, 30);
	BOX b2;
	return 0;
}