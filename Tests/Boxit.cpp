#include<iostream>
#include<string>

using namespace std;

class Box {
private:
	int length, breadth, height;
	string V;
public:
	Box(int l, int b, int h) :length{ l }, breadth{ b }, height{ h } {}
	Box() :length{ 0 }, breadth{ 0 }, height{ 0 } {}
	Box(Box& V) :length{ V.length }, breadth{ V.breadth }, height{ V.height } {}
	int getLength() {
		return length;
	}
	int getBreadth() {
		return breadth;
	}
	int getHeight() {
		return height;
	}
	long long CalculateVolume() {
		return length * breadth * height;
	}

	bool operator < (Box b) {
		if (length < b.length) {
			return true;
		}
		else if (breadth < b.breadth && length == b.length) {
			return true;
		}
		else if (height < b.height && breadth == b.breadth && length == b.length) {
			return true;
		}
		return false;
	}

	friend ostream& operator<<(ostream& os, const Box& b);
	/*{
		os << b.length << '/' << b.breadth << '/' << b.height;
		return os;
	}*/
};

ostream& operator<<(ostream& os, const Box& b)
{
	os << b.length << ' ' << b.breadth << ' ' << b.height;
	return os;
}


void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	/*long long V = 33004122803;
	cout << V << endl;*/
	check2();
}

//int main() {
//	Box B1(10, 50, 30);
//	Box b2;
//	cout << (b2 < B1) << endl;
//	cout << B1 << endl;
//	return 0;
//}