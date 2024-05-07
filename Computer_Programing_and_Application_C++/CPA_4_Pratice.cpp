#include <iomanip>
#include <iostream>

using namespace std;

void zong_da(int a, int W) { //a ­þ­Ó¦r  ²Ä´X¦C
	int i;

	for (i = W - 1; i >= 0; --i) {
		cout << (((a >> i) % 2) ? '*' : ' ');
	}
	cout << " ";
}

int main() {
	const int W = 5;
	const int H = 5;

	int Zong_Da[2][H] = { {0x4,0x1f,0x15,0x1f,0x4},{0x4,0x1f,0x4,0xa,0x11} };
	int i, j, k, l, m, n;

	for (i = 0; i < H; ++i) {
		for (j = 0; j < H; ++j) {
			for (l = 0; l < 2; ++l) {
				m = Zong_Da[l][i];
				for (k = W - 1; k >= 0; --k) {
					if ((m >> k) % 2 == 1)
					{
						n = (l + 1) % 2;
						zong_da(Zong_Da[n][j], W);
						cout << "  ";
					}
					else
					{
						cout << setw(2 * W - 2) << " ";
					}
				}
				cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
