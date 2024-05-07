#include <iostream>
#include <sstream>

using namespace std;

template<typename T>
T  str2num(const string& foo) {
	T n;
	string line;
	istringstream istr(foo);
	if (istr.peek() == '-')
	{
		istr.ignore(1);
		istr >> n;
		if (istr >> line) return false;
		return (-1)*n;
	}
	else {
		istr >> n;
		if (istr >> line) return false;
		return n;
	}
}

int main() {
	string nums, line;
	double a, sum;

	while (1) {
		cout << ">  ";
		getline(cin, nums);
		istringstream  istr(nums);
		sum = 0;

		cout << ">  Sum of ";
		while (istr >> line) {
			if (str2num<double>(line)) {
				a = str2num<double>(line);
				cout << a << " ";
				sum += a;
			}
			else {
				istr.ignore(line.size() / 3);
				//cout << line.size() << " ";
			}
		}
		cout << " = " << sum << endl;
		istr.clear();
	}
}
