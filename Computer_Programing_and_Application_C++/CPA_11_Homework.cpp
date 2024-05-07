#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

int main()
{
	srand(static_cast<unsigned>(time(NULL)));

	int i, j, k, n;
	int num, sum;
	int m[10];
	char c;
	string nums;
	istringstream istr;

	for (i = 0; i < 10; i++) { //建立字串
		m[i] = 20 + rand() % 10; //字串長度
		string line;
		cout << setw(2) << i + 1 << "> ";
		for (j = 0; j < m[i]; j++) {
			n = rand() % 62;
			if (n < 10) {
				c = n + '0';
				line += c;
			}
			else if (n < 36) {
				c = n - 10 + 'a';
				line += c;
			}
			else {
				c = n - 36 + 'A';
				line += c;
			}
			cout << c;
		}
		cout << endl;

		cout << "  > ";
		k = sum = 0;
		istr.str(line);
		while (!istr.eof()) {
			if (istr >> num) {
				sum += num;
				if (k > 0)cout << " + ";
				cout << num;
				k = 1;
			}
			else {
				istr.clear();
				istr.ignore(1);
			}
		}
		istr.clear();
		cout << " = " << sum << endl;
	}
}
