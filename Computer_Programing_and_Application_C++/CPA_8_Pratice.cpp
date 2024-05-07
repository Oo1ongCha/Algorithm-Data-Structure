#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int* str2int(const string& str) {
	int *p = new int[100];
	int i;
	istringstream istr(str);
	for (i = 0; i < 100; i++) {
		istr >> p[i];
	}
	return p;
}

int main()
{
	int i, j, k, l, m, n;
	int *fra;
	string fraction;

	cout << ">";
	getline(cin, fraction);
	fra = str2int(fraction);
	m = fraction.length();

	for (i = 0; i < m / 2 + 1; i++) {
		if (fra[i] > 0) cout << fra[i] << endl;
	}


}
