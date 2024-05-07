#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int main() {
	const int N = 2, R = 5, C = 5;
	int bitmap[N][R] = { {0x4,0x1f,0x15,0x1f,0x4} , {0x4,0x1f,0x4,0xa,0x11} };
	string ncu = "中大";

	int i, j, k, n, h, t, s, v, u;
	s = 0;
	while (1) {
		cout << "> ";
		cin >> n;

		for (s = 0; s < 2; ++s) {	// 上下兩字
			for (v = 0; v < R*n; ++v) {	// 每個字的縱向迴圈次數
				h = (s ? v + 1 : R * n - v);
				for (t = 0; t < 2 * n - 1; ++t) {	// 每個字的橫向字數
					k = n - abs(n - 1 - t);
					if (h > k*R) {
						cout << string(2 * k*C, ' ');
					}
					else {
						i = (s ? R - 1 - (k*R - h) / k : (k*R - h) / k);
						for (j = C - 1; j >= 0; --j) {	// 每個字內點陣迴圈
							if (bitmap[s][i] & (1 << j)) {
								for (u = 0; u < k; ++u) {
									cout << ncu[2 * s] << ncu[2 * s + 1];
								}
							}
							else cout << string(2 * k, ' ');
						}
					}
					cout << " ";
				}
				cout << endl;
			}
		}
		cout << endl;
	}
}
