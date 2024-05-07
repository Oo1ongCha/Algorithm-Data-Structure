#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

class Show_poems {
	vector <string> poem;
	vector <string> poems;
public:
	Show_poems(const string& fname) {
		ifstream infile(fname.c_str());
		string line;
		while (getline(infile, line)) {
			poem.push_back(line);
		}
	}

	void  shuffle(void) {
		int rp[7];
		int i, j, tmp;
		for (i = 0; i < 7; i++) rp[i] = i;
		for (i = 0; i < 7; i++) {
			j = rand() % 7;
			tmp = rp[i];
			rp[i] = rp[j];
			rp[j] = tmp;
		}
		for (i = 0; i < 7; i++) {
			poems.push_back(poem[rp[i]]);
		}
	}

	friend ostream& operator << (ostream& out, const Show_poems& foo) {
		int i, j, k, n;
		for (i = 0; i < 7; i++) {
			for (j = 0; j < 7; j++) {
				for (k = 0; k < 4; k++) {
					if (foo.poems[j].size() < 70) {
						if (i < 5) {
							n = 20 - 5 * (k + 1) + i;
							out << foo.poems[j][3 * n] << foo.poems[j][3 * n + 1] << foo.poems[j][3 * n + 2];
						}
						else out << "  ";
					}
					else {
						n = 28 - 7 * (k + 1) + i;
						out << foo.poems[j][3 * n] << foo.poems[j][3 * n + 1] << foo.poems[j][3 * n + 2];
					}
				}
				out << "  ";
			}
			out << endl;
		}
		return out;
	};
};

int main()
{
	srand(static_cast<unsigned>(time(NULL)));
	setlocale(LC_ALL, "zh_TW.UTF-8");

	Show_poems poems("poem.dat");

	poems.shuffle();

	cout << poems << endl;
}
