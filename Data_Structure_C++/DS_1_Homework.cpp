#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Show_Poems {
	vector <wstring> poems;
	vector <int> s;

public:

	Show_Poems(const string& fname) {
		wstring line;
		wifstream infile(fname.c_str());
		infile.imbue(locale("zh_TW.UTF-8"));
		while (getline(infile, line)) 	poems.push_back(line);
	}

	void shuffle() {
		int i, n;
		wstring tmp;
		for (i = 0; i < 7; i++) {
			n = rand() % 8;
			tmp = poems[i];
			poems[i] = poems[n];
			poems[n] = tmp;
		}
	}

	friend wostream& operator << (wostream& out, const Show_Poems& foo) {
		int i, j, k, n;
		for (i = 0; i < 7; i++) {
			for (j = 0; j < 8; j++) {
				for (k = 0; k < 4; k++) {
					if (foo.poems[j].size() > 25) {
						n = 21 - 7 * k + i;
						out << foo.poems[j][n];
					}
					else {
						if (i < 5) {
							n = 15 - 5 * k + i;
							out << foo.poems[j][n];
						}
						else out << "  ";
					}
				}
				out << "  ";
			}
			out << endl;
		}
		return out;
	};
};

int main() {
	srand(static_cast<unsigned>(time(NULL)));
	setlocale(LC_ALL, "zh_TW.UTF-8");

	Show_Poems poems("poem.dat");

	// 打亂各首詩的順序
	poems.shuffle();

	// 印出直式排列詩句
	wcout << poems << endl;
	return 0;
}
