#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i, j, k, m, n;

	string poem = "�K���M�ֺ��`�s���Ĥѳ¤Ψd�����ӥh�M�ϧg�l���k�󥲰ݿA��";

	n = 7;
	for (i = 0; i < n; i++) {
		cout << string(2 * (n - i + 1), ' ');
		for (j = 0; j < i + 1; j++) {
			k = i - j + 1;
			if ((i - j) % 2) { //�f
				m = (1 + n - k) * (n - k) / 2 + n - i - 1;
			}
			else { //��
				m = (n - k + 1) * (n - k) / 2 + j;
			}
			cout << poem[2 * m] << poem[2 * m + 1] << "  ";
		}
		cout << endl;
	}
	return 0;
}
