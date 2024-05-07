#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include<sstream>

using namespace std;

string  num2str(int s) {
	ostringstream  ostr;
	ostr << s;
	return  ostr.str();
}

int main() {
	int i, j, k, l, w;
	ifstream  infile("ncu.cc");
	ofstream  outfile;
	string line;
	string fname = "ncu", f2;

	int  ncu[2][5];

	for (i = 0; i < 5; i++) {
		getline(infile, ncu);

		ncu[i][j] = line[j];
		cout << ncu[i][j];

		cout << endl;
	}

	for (w = 2; w < 6; w++) {
		for (i = 0; i < 5; i++) {
			for (l = 1; l < w; l++) {
				for (j = 0; j < 11; j++) {
					for (k = 1; k < w; k++) {
						cout << ncu[i][j];
					}
					cout << endl;
				}
			}
		}
		//f2 = fname + num2str(w);
		//outfile.open(f2.c_str());
	}
}
