#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Fraction {
public:

	int num, den;

	Fraction(int a, int b)
		: num(a), den(b)
	{}

	friend Fraction  operator +(Fraction a, Fraction b) {
		return Fraction(a.num*b.den + a.den*b.num, a.den*b.den);
	}
	friend Fraction  operator - (Fraction a, Fraction b) {
		return Fraction(a.num*b.den - a.den*b.num, a.den*b.den);
	}
	friend Fraction  operator * (Fraction a, Fraction b) {
		return Fraction(a.num*b.num, a.den*b.den);
	}
	friend Fraction  operator / (Fraction a, Fraction b) {
		return Fraction(a.num*b.den, a.den*b.num);
	}
	friend Fraction operator+=(Fraction a, int b) {
		return Fraction(a.num + a.den * b, a.den);
	}
	friend Fraction  operator -=(Fraction a, Fraction b) {
		Fraction c = a - b;
		a = c;
		return c;
	}
	friend ostream& operator<< (ostream& out, const Fraction& foo) {
		return out << foo.num << "/" << foo.den;
	}

	friend istream& operator>> (istream& in, Fraction& foo) {
		char c;
		return in >> foo.num >> c >> foo.den;
	};
};

int main()
{
	Fraction a = Fraction(1, 2);
	Fraction b = Fraction(2, 3);

	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a / b << endl;

	a += 1;
	cout << a << endl;

	a -= b;
	cout << a << endl;
}
