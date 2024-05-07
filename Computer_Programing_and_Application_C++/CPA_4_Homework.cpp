#include<cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

void zong_da(int a, int W) { //a 哪個字  第幾列
	int i;

	for (i = W - 1; i >= 0; --i) {
		cout << (((a >> i) % 2) ? '*' : ' ');
	}
	cout << " ";
}

int main()
{
	srand(static_cast<unsigned>(time(NULL)));

	const int H = 5, W = 5;
	int Zong_Da[2][H] = { {0x4,0x1f,0x15,0x1f,0x4},{0x4,0x1f,0x4,0xa,0x11} };
	int p[5], q[4][2], i, j, k, l, m, n;

	p[4] = 2; //最少兩個
	for (i = 0; i < 4; i++) {
		(p[4] > 0) ? (p[i] = rand() % 2) : (p[i] = 1); //要不要印
		(p[i] == 0) ? (p[4]--) : (0);
		(p[i] == 1) ? (q[i][0] = rand() % 5) : (q[i][0] = 2 * H); //從哪印
		q[i][1] = rand() % 2; //印哪個字
	}

	for (i = 0; i < 2 * H - 1; i++) {
		for (j = 0; j < H; j++) {
			for (l = 0; l < 4; l++) {
				if (((i - q[l][0]) >= 0) && ((i - q[l][0]) < 5)) {
					m = Zong_Da[q[l][1]][i - q[l][0]];
					for (k = W - 1; k >= 0; --k) {
						if (((m >> k) % 2) == 1) {
							n = Zong_Da[q[l][1]][j];
							zong_da(n, W);
							cout << "  ";
						}
						else {
							cout << setw(2 * W - 2) << " ";
						}
					}
				}
				else {
					cout << setw(W*W + 3 * W) << " ";
				}
				cout << "  ";
			}
			cout << endl;
		}
	}
	return 0;
}
