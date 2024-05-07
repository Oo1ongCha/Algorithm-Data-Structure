#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i, j, k, m, n;

	string poem = "春風和煦滿常山芍藥天麻及牡丹遠志去尋使君子當歸何必問澤蘭";

	n = 7;
	for (i = 0; i < n; i++) {
		cout << string(2 * (n - i + 1), ' ');
		for (j = 0; j < i + 1; j++) {
			k = i - j + 1;
			if ((i - j) % 2) { //逆
				m = (1 + n - k) * (n - k) / 2 + n - i - 1;
			}
			else { //順
				m = (n - k + 1) * (n - k) / 2 + j;
			}
			cout << poem[2 * m] << poem[2 * m + 1] << "  ";
		}
		cout << endl;
	}
	return 0;
}
