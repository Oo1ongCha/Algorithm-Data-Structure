#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;
class Show_Poems {
	vector <wstring>  poem;
public:
	Show_Poems(const string& fname) {
		wifstream  infile (fname.c_str()) ;
		infile.imbue(locale("zh_TW.UTF-8"))  ;  // 用來表示檔案為 UTF-8 檔
		//infile.ignore(1);
		wstring line;

		while (getline(infile, line)) {
			poem.push_back(line);
		}
	}

	friend wostream& operator << (wostream& out, const Show_Poems& foo) {

		int i, j, k, n;
		for (i = 0; i < 7; i++) { // 7列
			for (j = 0; j < 7; j++) { // 7首詩
				for (k = 0; k < 4; k++) { // 4行
					if (foo.poem[j].size() < 25) {
						if (i < 5) {
							n = 20 - 5 * (k + 1) + i;
							out << foo.poem[j][n] ;
						}
						else out << "  ";
					}
					else {
						n = 28 - 7 * (k + 1) + i;
						out << foo.poem[j][n] ;
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
	setlocale( LC_ALL , "zh_TW.UTF-8" ) ;
	Show_Poems  foo("poem.dat");
	wcout << foo << endl;
}


