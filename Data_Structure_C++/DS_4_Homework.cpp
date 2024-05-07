#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

class Word {
private:
	int      uno;  // 中文字的萬國碼編號
	int      sno;  // 中文字筆劃
public:
	Word(int u, int s) : uno(u), sno(s) {};

	int Unicode() const { return uno; }

	int Stroke() const { return sno; }

	friend struct Rule;
};

struct Rule {
	bool operator()  (const Word& w1, const Word& w2) const {
		if (w1.sno == w2.sno) {
			return w1.uno > w2.uno;
		}
		else return w1.sno > w2.sno;
	}
};

int main()
{
	setlocale(LC_ALL, "zh_TW.UTF-8");
	//wcout.imbue(locale(""));

	wifstream  infile("strokes.dat");
	priority_queue< Word, vector<Word>, Rule > words;
	wistringstream istr;
	wstring line, ustr;
	int i, j, no, sno;

	while (getline(infile, line)) {
		istr.str(line);
		istr >> ustr >> sno;
		istr.clear();

		istr.str(ustr.substr(2));
		istr >> hex >> no;    // 當數字是 16 進位數字，需要 hex
		Word word(no, sno);
		words.push(word);
		istr.clear();
	}

	i = 1;
	j = 0;
	wcout << i << L"劃 : " << endl;
	while (!words.empty()) {
		if (words.top().Stroke() > i) {
			i++;
			wcout << endl << endl << i << L"劃 : " << endl;
		}
		int w = words.top().Unicode();
		wcout << static_cast<wchar_t>(w) << L" [ " << hex << w << L" ] ";
		words.pop();
		j++;
		if (j == 10) {
			j = 0;
			cout << endl;
		}
	}
}
