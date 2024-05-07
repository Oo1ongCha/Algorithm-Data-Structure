#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Idiom {
private:
	wstring       id;				  // 成語
	vector <int>    sno;  //  個別字筆劃
	int      allsno;				 // 總筆劃
public:
	Idiom(wstring i, vector <int> s, int all) :id(i), sno(s), allsno(all) {}

	int  all_stroke_no() const { return allsno; }

	int  first_stroke_no() const { return sno[0]; }

	friend wostream& operator << (wostream& out, const Idiom& foo) {
		return out << foo.id;
	}
	friend struct Rule;
};

struct Rule {
	bool operator()  (const Idiom& i1, const Idiom& i2) const {
		int i = 0;
		while (i < 4) {
			if (i1.sno[i] == i2.sno[i]) {
				i++;
				return i1.sno[i] > i2.sno[i];
			}
			else return i1.sno[i] > i2.sno[i];
		}
	}
};

int main()
{
	setlocale(LC_ALL, "zh_TW.UTF-8");

	wifstream  infilestr("strokes.dat");
	wistringstream istr;
	wstring line, ustr;
	int no, sno;

	typedef  wchar_t      unicode;
	typedef  int					stroke;
	map<unicode, stroke> words_db;

	while (getline(infilestr, line)) {
		istr.str(line);
		istr >> ustr >> sno;
		istr.clear();

		istr.str(ustr.substr(2));
		istr >> hex >> no;    // 當數字是 16 進位數字，需要 hex

		wchar_t wch = static_cast<wchar_t>(no);
		words_db.insert(make_pair(wch, sno));
		istr.clear();
	}
	infilestr.clear();

	wifstream  infileid("idioms.dat");
	infileid.imbue(locale("zh_TW.UTF-8"));
	priority_queue< Idiom, vector<Idiom>, Rule > idioms;
	wstring anidiom;
	map<unicode, stroke>::iterator  iter;
	vector<int>stroke_no;
	int i, j, n, m;

	while (getline(infileid, anidiom)) {
		n = 0;
		for (auto x : anidiom) {
			iter = words_db.find(x);
			m = iter->second;
			stroke_no.push_back(m);
			n += m;
		}

		Idiom idiom(anidiom, stroke_no, n);
		idioms.push(idiom);
		stroke_no.clear();
	}
	infileid.clear();

	i = idioms.top().first_stroke_no();
	j = 0;
	wcout << i << L" 劃 : " << endl;
	while (!idioms.empty()) {
		if (idioms.top().first_stroke_no() > i) {
			i++;
			wcout << endl << endl << i << L" 劃 : " << endl;
			j = 0;
		}
		if (j == 5) {
			wcout << endl;
			j = 0;
		}
		wcout << idioms.top() << " ";
		idioms.pop();
		j++;
	}
}
