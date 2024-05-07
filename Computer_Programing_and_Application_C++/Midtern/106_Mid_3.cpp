#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i, j, l, n;
	char c;

	cout << " >";
	cin >> n;

	for (i = 0; i < n; i++) { // 大行
		for (l = 0; l < n; l++) {//小行
			cout << string(n *(n - i - 1) + n - l - 1, ' ');
			for (j = 0; j < 2 * i + 2 * n; j++) {
				if (j % 2 == 1) {
					cout << (string(2 * (n - l) - 1, ' '));
				}
				else {
					((j > 2 * i + 1) && j < (2 * (n - 1))) ? c = 32 : c = l + 49;
					cout << string(2 * l + 1, c);
				}
			}
			cout << endl;
		}
	}
	// 倒
	for (i = n - 1; i >= 0; --i) { // 大行
		for (l = n - 1; l >= 0; --l) {//小行
			if (i == n - 1 && l == n - 1) continue;
			cout << string(n *(n - i - 1) + n - l - 1, ' ');
			for (j = 0; j < 2 * i + 2 * n; j++) {
				if (j % 2 == 1) {
					cout << (string(2 * (n - l) - 1, ' '));
				}
				else {
					((j > 2 * i + 1) && j < (2 * (n - 1))) ? c = 32 : c = l + 49;
					cout << string(2 * l + 1, c);
				}
			}
			cout << endl;
		}
	}
}
