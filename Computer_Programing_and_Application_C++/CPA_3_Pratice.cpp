#include <iostream>
#include<cstdlib>

using namespace std;

int main()
{
	int x, y, z, i, j, n, m, k, l;

	cout << "�x�}�j�p >";
	cin >> n >> m;

	cout << "����j�p >";
	cin >> k >> l;

	cout << endl;

	int **ptr_ma = new int*[n]; //�x�}n�C
	for (i = 1; i < m + 1; i++) {
		ptr_ma[i] = new int[m]; //m ��
	}

	int **ptr_bl = new int*[k]; //���k�C
	for (i = 1; i < l + 1; i++) {
		ptr_bl[i] = new int[l]; //l ��
	}

	for (i = 1; i < n + 1; i++) {//�x�}
		for (j = 1; j < m + 1; j++) {
			ptr_ma[i][j] = rand() % 9;
			cout << ptr_ma[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;


	for (y = 1; y < k + 1; y++) {// ��� �x�}
		for (i = 1; i < n+1; i++) {
			for (x = 1; x < l + 1; x++) {
				for (j = 1; j < m + 1; j++) {
					z = ((x-1)*k+y) % n;
					cout << ptr_ma[z][j] << " ";
				}
				cout << "  ";
			}
			cout << endl;
		}
		cout << endl;
	}


	return 0;
}
