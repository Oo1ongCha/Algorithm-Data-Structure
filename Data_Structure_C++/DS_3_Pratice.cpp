// DS Pratice 3.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

// 函式物件類別
struct By_Small_Color_Distance {
	Color c;
	By_Small_Color_Distance(const Color& color) : c(color) {}
	bool operator() (const Color& c1, const Color& c2) const {
		return c.distance(c1) < c.distance(c2);
	}
};

class Color {
private:
	string cname;
	int r, g, b;
public:
	Color() {
		while (getline(infile, line)) {
			line >> color.cname >> r >> g >> b;
			color_table.push_back(color);
		}
	}
	Color(string s, int r2, int g2, int b2) : cname(s), r(r2), g(g2), b(b2) {
	}

	string colorname() const { return cname; }
	double distance(const Color& c2) const { ... }

	friend ostream& operator<<(ostream& out, const Color& foo) {
		return out << hex << setfill(’0’)
			<< setw(2) << foo.r << setw(2) << foo.g << setw(2) << foo.b
			<< " " << foo.cname << dec << setfill(’ ’);
	}
	friend struct By_Small_Color_Distance;
};

int main()
{
	string colorname;

	ifstream  infile("Color.dat");
	string line;
	Color color;

	vector <vector <Color > > color_table;
	while (getline(infile, line)) {
		line >> color.cname >> r >> g >> b;
		color_table.push_back(color);
	}

	cout << "> ";
	cin >> colorname;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的秘訣:
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案