#include <iostream>
#include <string>
using namespace std;

int number_0(int n) {
	int number[5] = { 7,5,5,5,7 };
	return number[n];
}
int number_1(int n) {
	int number[5] = { 2,2,2,2,2 };
	return number[n];
}
int number_2(int n) {
	int number[5] = { 7,1,7,4,7 };
	return number[n];
}
int number_3(int n) {
	int number[5] = { 7,1,7,1,7 };
	return number[n];
}
int number_4(int n) {
	int number[5] = { 5,5,7,1,1 };
	return number[n];
}
int number_5(int n) {
	int number[5] = { 7,4,7,1,7 };
	return number[n];
}
int number_6(int n) {
	int number[5] = { 7,4,7,5,7 };
	return number[n];
}
int number_7(int n) {
	int number[5] = { 7,1,1,1,1 };
	return number[n];
}
int number_8(int n) {
	int number[5] = { 7,5,7,5,7 };
	return number[n];
}
int number_9(int n) {
	int number[5] = { 7,5,7,1,7 };
	return number[n];
}

void print(int n) {
	int i;
	for (i = 2; i >= 0; --i) {
		if (n == 7) {
			cout << string(3, '=');
		}
		else {
			cout << ((n >> i) % 2 ? "| |" : "   ");
		}
	}
}

int main()
{
	int i, j, k, n;
	char num;

	while (1) {
		string number;
		cout << ">";
		cin >> number;
		n = number.length();

		for (i = 0; i < 5; i++) { // 5*2行
			for (k = 0; k < 2; k++) { //重複兩次
				for (j = 0; j < n; j++) { //n個數字
					num = number[j];
					switch (num) {
					case  '0':
						print(number_0(i));
						break;
					case  '1':
						print(number_1(i));
						break;
					case  '2':
						print(number_2(i));
						break;
					case  '3':
						print(number_3(i));
						break;
					case  '4':
						print(number_4(i));
						break;
					case  '5':
						print(number_5(i));
						break;
					case  '6':
						print(number_6(i));
						break;
					case  '7':
						print(number_7(i));
						break;
					case  '8':
						print(number_8(i));
						break;
					case  '9':
						print(number_9(i));
						break;
					}
					cout << "  ";
				}
				cout << endl;
			}
		}
	}
}
