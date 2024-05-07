#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

class Score {
private:
	wstring name, dept;
	vector<int> scores;
	int total;

public:
	Score(wstring n, wstring d, vector <int> s, int t) :name(n), dept(d), scores(s), total(t) {};

	int compute_total(const vector<double>&);

	int total_s() const { return total; }

	wstring depart() const { return dept; }

	friend bool operator> (const Score&, const Score&);

	friend wistream& operator>>(wistream&, Score&);
	friend wostream& operator<<(wostream& out, const Score& s) {
		out << s.name << L" " << s.dept << L" ";
		for (auto x : s.scores) out << setw(3) << x << L" ";
		return out << L"--> " << setw(3) << s.total;
	}
};

bool operator> (const Score& s1, const Score& s2) {
	if (s1.total == s2.total) {
		int i = 0;
		while (s1.scores[i] == s2.scores[i]) {
			return s1.scores[i] > s2.scores[i];
			i++;
		}
		return s1.scores[i] > s2.scores[i];
	}
	else return s1.total > s2.total;
}

struct Rule {
	bool operator() (wstring w1, wstring w2) const {
		return w1[0] < w2[0];
	}
};

typedef pair<wstring, double> PAIR;

struct Rule2 {
	bool operator()  (const pair<wstring, double>& p1, const pair<wstring, double>& p2) {
		return p1.second > p2.second;
	}
};

int main()
{
	setlocale(LC_ALL, "zh_TW.UTF-8");

	wifstream infile("MA101.txt");
	infile.imbue(locale("zh_TW.UTF-8"));
	wistringstream istr;
	wstring w = L"#";
	wstring ww = L"配分百分比";
	wstring line;

	vector <Score > all;
	wstring name, dept;
	vector <int> scores;
	vector <double> p;
	double d, total;
	int i, n;

	while (getline(infile, line)) {
		if (line[0] == w[0]) continue;

		istr.str(line);
		istr >> name;
		if (name == ww) {
			for (i = 0; i < 4; ++i) {
				istr >> d;
				d = d / 100;
				p.push_back(d);
			}
		}

		else {
			istr >> dept;
			total = 0;
			for (i = 0; i < 4; ++i) {
				istr >> n;
				total += n * p[i];
				scores.push_back(n);
			}
			Score score(name, dept, scores, total);
			all.push_back(score);
		}
		istr.clear();
		scores.clear();
	}

	sort(all.begin(), all.end(), greater<Score>());

	typedef wstring Dept;
	map < Dept, set<Score, greater<Score> > > dscores;
	map < Dept, set<Score, greater<Score> > >::iterator iter;
	set <wstring> depts;

	for (auto x : all) {
		depts.insert(x.depart());
	}

	for (auto x : depts) {
		set<Score, greater<Score> > ss;
		for (auto y : all) {
			if (y.depart() == x) {
				ss.insert(y);
			}
		}
		dscores.insert(make_pair(x, ss));
	}

	vector <pair<wstring, double> > mpdeor;
	int k;
	double  avg;

	for (auto x : dscores) {
		k = 0;
		for (auto y : x.second)k += y.total_s();
		avg = k / x.second.size();
		mpdeor.push_back(make_pair(x.first, avg));
	}

	sort(mpdeor.begin(), mpdeor.end(), Rule2());

	for (auto x : mpdeor) {
		k = 0;
		i = 1;
		iter = dscores.find(x.first);
		wcout << x.first << L" : " << iter->second.size() << L" " << L"平均 : " << x.second << endl;
		for (auto y : iter->second) {
			wcout << L"[" << i << L"] " << y << endl;
			i++;
		}
		wcout << endl;
	}
}
