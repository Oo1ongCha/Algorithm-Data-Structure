#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	srand(static_cast<unsigned>(time(NULL)));

	int i, j, k, n, m;
	string poem = "�K�v��ı��B�B�D�ڳ��]�ӭ��B�n�Ḩ���h��";

	int r[6] = { 5,6,7,8,9,10 }; //�L�X��

	for (i = 0; i < 6; i++) {  //�洫
		n = rand() % 6;
		k = r[i];
		r[i] = r[n];
		r[n] = k;
	}

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 6; j++) {
			for (k = 0; k < 4; k++) {
				if (i < r[j]) {
					m = 4 * r[j] - (k + 1) *  r[j] + i;
					if ((m >= 0) && (m < 20)) {
						cout << poem[2 * m] << poem[2 * m + 1] << " "; //
					}
					else {
						cout << "     ";
					}
				}
				else {
					cout << string(5, ' ');
				}
			}
			cout << "  ";
		}
		cout << endl;
	}
}
