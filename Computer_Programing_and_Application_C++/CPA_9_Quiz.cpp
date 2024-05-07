#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

string  num2str(int s) {
	ostringstream  ostr;
	ostr << s;
	return  ostr.str();
}

int main()
{
	int i, k, n;
	ifstream infile("C:\\Users\\USER\\source\\repos\\Pratice 9\\Pratice 9\\ncu.dat");
	ofstream outfile("C:\\Users\\USER\\source\\repos\\Pratice 9\\Pratice 9\\ncu.txt");
	string line, ncu[5];

	for (i = 0; i < 5; i++) {
		getline(infile, line);
		ncu[i] = line;
	}

	cout << ">";
	cin >> n;

	for (i = 0; i < 5; i++) {
		for (k = 0; k < n; k++) {
			outfile << ncu[i];
		}
		outfile << endl;
	}
}
