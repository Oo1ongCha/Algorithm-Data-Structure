#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

class Num_Base {
private:

	int num;
	int Num10[2];

public:

	void setno(int n) { //設定數字
		num = n;
		for (int i = 0; i < 2; i++) { //分割數字
			Num10[i] = num % 10;
			num = num / 10;
		}
	}

	int base(int b) {
		int  Numb = 0;
		for (int i = 1; i >= 0; i--) {
			if (Num10[i] < b) { Numb += (int)pow(b, i)*Num10[i]; }
			else {
				Numb = -1;
				break;
			}
		}
		return Numb;
	};
};

int main() {

	setlocale( LC_ALL , "zh_TW.UTF-8" ) ;

	int b, n;
	Num_Base no;
	cout << setw(4) << " ";
	for (b = 2; b <= 12; ++b) {
		cout << setw(3) << b << "進位";
	}
	cout << endl;

	for (n = 10; n <= 40; ++n) {
		no.setno(n);
		cout << setw(2) << n;
		for (b = 2; b <= 12; ++b) {
			if (no.base(b) > 0) cout << setw(7) << no.base(b);
			else  cout << setw(7) << "*";
		}
		cout << endl;
	}
}
