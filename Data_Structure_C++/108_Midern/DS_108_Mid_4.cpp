#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>

using namespace std;

struct Rule {
	bool operator() ( wstring w1,  wstring w2) const {
		if (w1.size() == w2.size()) {
			return w1[0] < w2[0];
		}
		else return w1.size() < w2.size();
	}
};

int main()
{
	setlocale(LC_ALL, "zh_TW.UTF-8");

	wifstream infile("unique.dat");
	infile.imbue(locale("zh_TW.UTF-8"));
	infile.ignore(1);

	//priority_queue <wstring ,vector <wstring>, Rule > poems;
	vector <wstring> poems;
	wstring line;
	int n;

	while (getline(infile, line)) {
		auto result = unique(line.begin(), line.end());
		line.resize(distance(line.begin(), result));
		poems.push_back(line);
	}
	
	sort(poems.begin(), poems.end(), Rule());

	auto result = unique(poems.begin(), poems.end());
	poems.resize(distance(poems.begin(), result));

	for (auto x : poems) {
		n = x.size();
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < n/5; j++) {
				wcout << x[n - 5 - 5 * j + i]<<" ";
			}
			wcout << endl;
		}
		cout << endl;
	}

}
