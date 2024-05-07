#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i, j, n, m;

	string poem = "春風和煦滿常山芍藥天麻及牡丹遠志去尋使君子當歸何必問澤蘭";

	n = 7;
	for (i = 0; i < n; i++) {
		cout << string(2 * (n - i+2), ' ');
		for (j = 0; j < i + 1; j++) {
			m = 2 * ((i - j) * (2 * n - (i - j) + 1) / 2 + j);
			cout << poem[m] << poem[m + 1] << "  ";
		}
		cout << endl;
	}

	return 0;
}
