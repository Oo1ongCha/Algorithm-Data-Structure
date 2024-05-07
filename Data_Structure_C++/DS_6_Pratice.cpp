#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	setlocale(LC_ALL, "zh_TW.UTF-8");

	wistringstream istr;
	wifstream infile("poem.dat");
	infile.imbue(locale("zh_TW.UTF-8"));
	wstring line;

	while (getline(infile, line)) {
		auto result = unique(line.begin(), line.end());
		line.resize(distance(line.begin(), result));
		wcout << line << endl;
	}
}
