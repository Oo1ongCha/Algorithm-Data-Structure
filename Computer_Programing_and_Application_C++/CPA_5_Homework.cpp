#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i, j, k, n, m;
	string poem = "春眠不覺曉處處聞啼鳥夜來風雨聲花落知多少";

	n = 5;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 6; j++) {
			for (k = 0; k < 4; k++) {
				if (i < n) {
					m = 4 * n - (k + 1) * n + i;
					if ((m >= 0) && (m < 20)) {
						cout << poem[2 * m] << poem[2 * m + 1] << " ";
					}
					else {
						cout << "     ";
					}
				}
				else {
					cout << string(5,' ');
				}
			}
			cout << "  ";
			n++;
		}
		cout << endl;
		n = 5;
	}
}
