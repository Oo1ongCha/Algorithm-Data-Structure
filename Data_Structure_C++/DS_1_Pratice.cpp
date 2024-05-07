#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "zh_TW.UTF-8");
	int i, j, k;
	vector <wstring> poem5, poem7;
	wstring line;

	wifstream infile7("poem7.dat");
	infile7.imbue(locale("zh_TW.UTF-8"));
	infile7.ignore(1);
	while (getline(infile7, line)) {
		poem7.push_back(line);
	}
	infile7.clear();

	wifstream infile5("poem5.dat");
	infile5.imbue(locale("zh_TW.UTF-8"));
	infile5.ignore(1);
	while (getline(infile5, line)) {
		poem5.push_back(line);
	}
	infile5.clear();

	for (i = 0; i < 7; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 4; k++) {
				if (j % 2 == 0) {// 7
					wcout << poem7[3 - k][i];
				}
				else { //5
					if (i < 5) {
						wcout << poem5[3 - k][i];
					}
					else {
						wcout << wstring(4, ' ');
					}
				}
			}
			wcout << "  ";
		}
		wcout << endl;
	}
}
