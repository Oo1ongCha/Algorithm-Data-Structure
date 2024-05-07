#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Color {
private:
	string cname;
	int r, g, b;
public:
	Color() {}

	Color(string s, int r2, int g2, int b2) : cname(s), r(r2), g(g2), b(b2) {}

	string colorname() const { return cname; }

	double distance(const Color& c2) const {
		double n = sqrt(2 * ((r - c2.r) * (r - c2.r)) + 4 * ((g - c2.g) * (g - c2.g)) + 3 * ((b - c2.b) * (b - c2.b)) + ((r + c2.r) / 2) * (((r - c2.r) * (r - c2.r)) - ((b - c2.b) * (b - c2.b))) / 256);
		return n;
	}

	friend ostream & operator<<(ostream & out, const Color & foo) {
		return out << hex << setfill('0')
			<< setw(2) << foo.r << setw(2) << foo.g << setw(2) << foo.b
			<< " " << foo.cname << dec << setfill(' ');
	}
	friend struct By_Small_Color_Distance;
};

// 函式物件類別
struct By_Small_Color_Distance {
	Color c;
	By_Small_Color_Distance(const Color& color) : c(color) {}
	bool operator() (const Color& c1, const Color& c2) const {
		return c.distance(c1) < c.distance(c2);
	}
};

struct By_Alphabet {
	Color c;
	By_Alphabet(const Color& color) : c(color) {}
	bool operator() (const Color& c1, const Color& c2) const {
		return c1.colorname() < c2.colorname();
	}
};

int main()
{
	ifstream  infile("color.dat");
	istringstream istr;
	int r, g, b;
	string line, color_name;
	Color color;
	vector <Color > color_table;

	while (getline(infile, line)) {
		istr.str(line);
		istr >> color_name >> r >> g >> b;
		Color color(color_name, r, g, b);
		color_table.push_back(color);
		istr.clear();
	}

	sort(color_table.begin(), color_table.end(), By_Alphabet(color));

	//string colorname;
	cout << "> ";
	//cin >> colorname;

	int d;
	cin >> d;

	vector <int > color_count;
	for (auto& x : color_table) {
		int n = 0;
		for (auto& y : color_table) {
			if ((y.distance(x) < d) && (y.distance(x) > 0))n = n + 1;
		}
		color_count.push_back(n);
	}

	//sort(color_table.begin(), color_table.end(), By_Small_Color_Distance(color));

	/*for (int i = 1; i < 11; i++) {
		cout << setw(2) << ":" << setw(5) << fixed << setprecision(1)
			<< color_table[i].distance(color) << "  " << color_table[i] << endl;
	}*/

	int i = 0;
	for (i = 0; i < color_count.size(); i++) {
		if (color_count[i] > 0) cout << color_table[i].colorname() << " : " << color_count[i] << endl;
	}
}
