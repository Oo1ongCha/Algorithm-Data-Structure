#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class Same_word {
private:
	vector <wchar_t > wc;
	int strno;
public:
	Same_word(vector <wchar_t > w, int s) : wc(w), strno(s) {};

	friend wostream& operator<<(wostream& out, const Same_word foo) {
		out << setw(4) << hex << foo.strno << " : ";
		for (auto x : foo.wc) out << x << " ";
		return out << endl;
	}

	friend struct Rule;
};

struct Rule {
	bool operator()  (const Same_word& w1, const Same_word& w2) const {
		return w1.strno < w2.strno;
	}
};

int main()
{
	setlocale(LC_ALL, "zh_TW.UTF-8");

	wifstream infilewd("strokes.dat");
	wistringstream istr;
	wstring line, ustr;
	int sno, no;
	wchar_t wch;

	typedef  wchar_t      unicode;
	typedef  int					stroke;
	map<unicode, stroke> words_db;

	while (getline(infilewd, line)) {
		istr.str(line);
		istr >> ustr >> sno;
		istr.clear();

		istr.str(ustr.substr(2));
		istr >> hex >> no;

		wch = static_cast<wchar_t>(no);
		words_db.insert(make_pair(wch, sno));
		istr.clear();
	}
	infilewd.close();

	wifstream infilep("poem.dat");
	infilep.imbue(locale("zh_TW.UTF-8"));

	priority_queue< Same_word, vector<Same_word>, Rule > sw;
	map<unicode, stroke>::iterator  iter;
	vector <wchar_t> poem;
	vector <wchar_t> samew;
	vector <int> poem_str;
	vector<int>::iterator it;
	wstring w = L"，。";
	int n, m, k;

	while (getline(infilep, line)) {
		for (auto x : line) {
			if (x == w[0] or x == w[1]) continue;
			iter = words_db.find(x);
			n = iter->second;
			poem.push_back(x);
			poem_str.push_back(n);
		}
	}
	infilep.close();

	wcout << L"(A):" << endl << endl;

	it = adjacent_find(poem_str.begin(), poem_str.end());
	while (it != poem_str.end()) {
		n = distance(poem_str.begin(), it);
		k = *it;
		wcout << setw(4) << hex << k << L" : ";
		wcout << poem[n] << L" " << poem[n + 1] << L" ";

		samew.push_back(poem[n]);
		samew.push_back(poem[n + 1]);

		it = adjacent_find(++it, poem_str.end());
		m = distance(poem_str.begin(), it);

		while (m - n < 2) {
			wcout << poem[m + 1] << L" ";
			samew.push_back(poem[m + 1]);

			it = adjacent_find(++it, poem_str.end());
			m = distance(poem_str.begin(), it);
		}
		wcout << endl;

		Same_word ss(samew, k);
		sw.push(ss);
		samew.clear();
	}

	wcout << endl << L"(B):" << endl << endl;

	while (!sw.empty()) {
		wcout << sw.top();
		sw.pop();
	}
}
