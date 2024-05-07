#include <iostream>
#include <fstream>
#include <sstream>
#include <vector >
#include <map>
#include <set>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "zh_TW.UTF-8");

	wifstream infile("class.dat");
	infile.imbue(locale("zh_TW.UTF-8"));

	wstring line, str, course;
	int i, k, n;
	//map<wstring, set <wstring> > cc;
	map<wstring, set <int> > cs;
	wstring cnum = L" 一二三四五";

	wistringstream istr;
	wostringstream ostr;

	i = 1;
	while (getline(infile, line)) {
		if (i > 2 and i != 7) {
			istr.str(line);
			istr >> n >> str;
			k = 1;
			while (istr >> course) {
				if (course != L"--") {
					//ostr << cnum[k] << L":" << n;
					ostr << k * 10 + n;
					//cc[course].insert(ostr.str());
					cs[course].insert(k * 10 + n);
					ostr.str(L"");
				}
				k += 1;
			}
			istr.clear();
		}
		i += 1;
	}

	map<int, wstring> foo;

	for (auto x : cs) {
		for (auto y : x.second) {
			foo[y] = x.first;
			break;
		}
	}

	for (auto w : foo) {
		auto x = w.second;
		wcout << x << " : ";
		for (auto y : cs[x]) {
			wcout << cnum[y / 10] << ":" << y % 10 << " ";
		}
		wcout << endl;
	}

	/*
	for (auto x : cs) {
		wcout << x.first << " : ";
		for (auto y : x.second) {
			wcout << cnum[y / 10] << ":" << y % 10 << " ";
		}
		wcout << endl;
	}*/
}
