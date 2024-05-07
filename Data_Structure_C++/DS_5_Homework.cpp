#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Idiom {
private:
	wstring       id;				  // 成語
	int      samechs;			  // 相同字數
public:
	Idiom(wstring i, int s) :id(i), samechs(s) {}

	int   samechs_no() const { return samechs;; }

	friend wostream& operator << (wostream& out, const Idiom& foo) {
		return out << foo.id;
	}
	friend struct Rule;
};

struct Rule {
	bool operator()  (const Idiom& i1, const Idiom& i2) const {
		return i1.samechs < i2.samechs;
	}
};

int main()
{
	setlocale(LC_ALL, "zh_TW.UTF-8");

	wifstream  infile1("idioms.dat");
	infile1.imbue(locale("zh_TW.UTF-8"));

	priority_queue< Idiom, vector<Idiom>, Rule > idioms;
	vector <wstring> allidioms;
	wstring anidiom;

	int i, j, n;

	while (getline(infile1, anidiom)) allidioms.push_back(anidiom);
	infile1.clear();

	wifstream infile2("idioms.dat");
	infile2.imbue(locale("zh_TW.UTF-8"));

	while (getline(infile2, anidiom)) {
		wcout << anidiom << endl; //

		for (auto y : allidioms) {
			n = 0;
			for (auto x : anidiom) {
				if (anidiom == y)continue; //相同成語 跳過
				for (auto z : y) { //y成語每個字
					if (x == z) n++;
				}
			}
			if (n > 0) {
				Idiom idiom(y, n);
				idioms.push(idiom);
			}
		}

		if (!idioms.empty()) {
			i = idioms.top().samechs_no();
			j = 0;
			wcout << L">" << i << L" : ";
			while (!idioms.empty()) {
				if (idioms.top().samechs_no() < i) {
					i--;
					wcout << endl << L">" << i << L" : ";
					j = 0;
				}
				if (j == 10) {
					wcout << endl << wstring(5, L' ');
					j = 0;
				}
				wcout << idioms.top() << " ";
				idioms.pop();
				j++;
				if (idioms.empty()) cout << endl;
			}
		}
		cout << endl;
	}
	infile2.clear();
}
