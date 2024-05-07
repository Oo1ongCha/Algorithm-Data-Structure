#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

void cout_container(vector<string> n) {
	for (int i = 0; i < n.size(); i++) {
		cout << n[i] << " ";
	}
	cout << endl;
}

struct datasort { //(1) 先比數字，由小到大 (2) 再比字母，由小到大
	bool operator () (string a, string b)const {
		if ((a[2] * 10 + a[3]) == (b[2] * 10 + b[3])) {
			return a[0] < b[0];
		}
		else return (a[2] * 10 + a[3]) < (b[2] * 10 + b[3]);
	}
};

int  main() {
	ifstream  infile("File.dat");
	istringstream  istr;
	string    lines, line;
	vector<string>  data;

	infile.ignore(3);
	while (getline(infile, lines)) {
		istr.str(lines);
		while (istr >> line) data.push_back(line);
		istr.clear();

		sort(data.begin(), data.end(), datasort());

		cout_container(data);
		cout << endl;
		data.clear();
	}
}
