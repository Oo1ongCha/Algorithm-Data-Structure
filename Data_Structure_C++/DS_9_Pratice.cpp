// Pratice 9.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include "pch.h"
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
	int i, j, k, n;
	//ifstream infile("D:\\Program Language\\Visual C++ Project\\Homework10\\Homework10\\poem1.dat");
	//ifstream infile("D:\\Program Language\\Visual C++ Project\\Pratice 9\\Pratice 9\\ncu.dat");
	wifstream infile("D:\\Program Language\\Visual C++ Project\\Pratice 9\\Pratice 9\\poem.dat");
	//ofstream outfile("D:\\Program Language\\Visual C++ Project\\Pratice 9\\Pratice 9\\ncu.txt");
	wstring line;
	vector <wstring> ncu;

	i = 0;
	while (getline(infile, line)) {
		ncu.push_back(line);
		i += 1;
	}

	wcout << ncu[0].size() << endl;

	wcout << ">";
	wcin >> n;

	for (j = 0; j < i; j++) {
		for (k = 0; k < n; k++) {
			wcout << ncu[j][0] << ncu[j][1] << ncu[j][2] << " ";
		}
		wcout << endl;
	}
	/*
	for (j = 0; j < i; j++) {
		for (k = 0; k < n; k++) {
			outfile << ncu[j] << " ";
		}
		outfile << endl;
	}*/
}

/*
for (i = 0; i < 7; i++) {
	for (j = 0; j < 7; j++) {
		for (k = 0; k < 4; k++) {
			if (size(poem[j]) == 40) {
				if (poem5[i][k] > -1) cout << poem[j][2 * poem5[i][k]] << poem[j][2 * poem5[i][k] + 1];
				else cout << "  ";
			}
			else cout << poem[j][2 * poem7[i][k]] << poem[j][2 * poem7[i][k] + 1];
		}
		cout << "  ";
	}
	cout << endl;
}*/

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的秘訣:
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案