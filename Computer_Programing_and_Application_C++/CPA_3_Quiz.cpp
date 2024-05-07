#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int i, j, n, m, k, l;

	cout << "¯x°}¤j¤p";
	cin >> n >> m;

	int **ptr = new int*[n];
	for (i = 1; i < n + 1; i++) {
		ptr[i] = new int[m];
	}

	for (i = 1; i < n + 1; i++) {
		for (j = 1; j < m + 1; j++) {
			ptr[i][j] = rand() % 9 + 1;
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;

	int x = 1;

	for (l = 1; i < n + 1; i++) {
		for (i = 1; i < n + 1; i++) {
			for (k = 1; k < l + 1; k++) {
				for (j = 1; j < m + 1; j++) {
					cout << ptr[x][j] << " ";
					x++;
					x = x % (n - 1) + 1;
					if (j == m) {
						cout << " ";
					}
				}
				if (k == l) {
					cout << endl;
				}
				cout << endl << endl;
			}
		}
	}
}
