#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <stdlib.h>
#include <algorithm>

using namespace std;

template <class T>
vector <T> shuffle(vector <T> x, int m) {
	T tmp;
	for (int i = 0; i < x.size(); i++) {
		int n = rand() % (x.size());
		tmp = x[i];
		x[i] = x[n];
		x[n] = tmp;
	}
	x.resize(m);
	return x;
}

class List {
private:
	string dep;
	int num;
public:
	List() {}

	List(string d, int n) : dep(d), num(n) {}

	string depname() const { return dep; }

	int Num_of_student() const { return num; }

	friend ostream& operator<<(ostream& out, const List& foo) {
		return out << foo.dep << "_" << setw(3) << setfill('0') << foo.num;
	}
};

int main()
{
	srand(static_cast<unsigned>(time(NULL)));
	setlocale(LC_ALL, "zh_TW.UTF-8");

	ifstream  infile("List.dat");
	istringstream istr;
	vector <List> list;
	vector <vector <List> > lists;
	vector <string> dep;
	vector <int > protection_quota, game_list;
	vector <List> waitlist;
	string line, d;
	int n, m, i, j, k;

	while (getline(infile, line)) {
		istr.str(line);
		istr >> d >> n;
		protection_quota.push_back(n);
		dep.push_back(d);

		for (i = 1; i < 10 * n; i++) {
			List gl(d, i);
			list.push_back(gl);
		}
		lists.push_back(shuffle(list, n + 10));
		list.clear();
		istr.clear();
	}

	wcout << L"各系比賽名單" << endl;
	k = 0;
	for (i = 0; i < 7; i++) {
		n = protection_quota[i];
		m = k + (rand() % (n / 3 + 1)) + ((5 * n) / 6) + 1;
		k += n;
		if (m > 45) m = 45;
		game_list.push_back(m);
	}

	for (i = 0; i < 7; i++) {
		n = protection_quota[i];
		if (i == 0) m = game_list[0];
		else m = game_list[i] - game_list[i - 1];
		cout << dep[i] << " (" << setw(2) << setfill('0') << m << "/" << setw(2) << setfill('0') << n << ") : ";

		if (m > n) {
			for (j = 0; j < n; j++) 	cout << lists[i][j] << " ";
			cout << "[ ";
			for (j = n; j < m; j++) {
				cout << lists[i][j] << " ";
				waitlist.push_back(lists[i][j]);
			}
			cout << "]";
		}
		else {
			for (j = 0; j < m; j++) 	cout << lists[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	wcout << L"後補順序:" << endl;
	if (waitlist.size() > 0) {
		for (i = 0; i < waitlist.size(); i++) {
			cout << i + 1 << " : " << waitlist[i] << endl;
		}
	}
	else wcout << L"無";
}
