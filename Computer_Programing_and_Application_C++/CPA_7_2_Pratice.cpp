#include <iostream>
#include <string>

using namespace std;

const int N = 10, R = 5, C = 4;

class Cbitmap {
private:

	static  const int bitmap[N][R];   // 常數值在末尾設定
	string  bstr;

public:

	Cbitmap() {}
	Cbitmap(const string& foo) : bstr(foo) {}

	void  set_num(const string& foo) {
		bstr = foo;
	}

	void print_little(int num, int n) {
		int i;
		for (i = 3; i >= 0; i--) {
			if ((num >> i) % 2 == 1) cout << n;
			else cout << " ";
		}
	}

	void print_big(int num, int m, int l) {
		int i;
		for (i = 3; i >= 0; i--) {
			if ((num >> i) % 2 == 1) print_little(l, m);
			else cout << string(4, ' ');
			cout << " ";
		}
	}

	void  display() {
		int i, j, k, l, m, p;
		int n = bstr.length();
		for (i = 0; i < 5; i++) { //大行
			for (l = 0; l < 5; l++) { //小行
				for (j = 0; j < n; j++) { //幾個數字
					k = bstr[j] - 48;
					m = bitmap[k][i];
					p = bitmap[k][l];
					print_big(m, k, p); //bitmap[k][i], k, bitmap[k][l]
					cout << "  ";
				}
				cout << endl;
			}
			cout << endl;
		}
	}
	void  display_inverse() {
		int i, j, k, l, m, p;
		int n = bstr.length();
		for (i = 0; i < 5; i++) { //大行
			for (l = 0; l < 5; l++) { //小行
				for (j = 0; j < n; j++) { //幾個數字
					k = bstr[j] - 48;
					m = bitmap[k][4 - i];
					p = bitmap[k][4 - l];
					print_big(m, k, p); //bitmap[k][i], k, bitmap[k][l]
					cout << "  ";
				}
				cout << endl;
			}
			cout << endl;
		}
	};
};

int main() {
	Cbitmap foo;
	string  str;

	while (1) {
		cout << " > ";
		cin >> str;

		foo.set_num(str);
		foo.display();
		foo.display_inverse();
	}
}

// 請留意這裡的設定方式，不須 static
const int  Cbitmap::bitmap[N][R] = {
	{0xf,0x9,0x9,0x9,0xf},{0x2,0x2,0x2,0x2,0x2},{0xf,0x1,0xf,0x8,0xf},
	{0xf,0x1,0x7,0x1,0xf},{0xa,0xa,0xf,0x2,0x2},{0xf,0x8,0xf,0x1,0xf},
	{0xf,0x8,0xf,0x9,0xf},{0xf,0x9,0x1,0x1,0x1},{0xf,0x9,0xf,0x9,0xf},
	{0xf,0x9,0xf,0x1,0xf} };
