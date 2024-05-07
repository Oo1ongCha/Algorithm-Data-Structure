#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

void cout_container(vector<int> n, string str) {
	cout << " " << n[0];
	for (int i = 1; i < n.size(); i++) {
		cout << str << n[i];
	}
	cout << endl;
}

int randint(int a, int b) {
	int n = rand() % (b - a + 1);
	return n + a;
}

struct large_digit_sum {
	bool operator () (int a, int b)const {
		if ((a % 10 + a / 10) == (b % 10 + b / 10)) {
			return a > b;
		}
		else return (a % 10 + a / 10) > (b % 10 + b / 10);
	}
};

int  main() {
	// 設定數字起始種子
	srand(static_cast<unsigned>(time(NULL)));

	char  data[] = "hw2.dat";

	ofstream  outfile(data);

	int i, j, n, maxline;

	// 數字列數，randint(a,b) 為產生 [a,b] 的亂數
	maxline = randint(10, 30);

	// 產生 maxline 列的數字存入 outfile 檔
	for (i = 0; i < maxline; ++i) {
		// 每列數字為 n 介於 [3,7] 之間
		n = randint(3, 7);
		for (j = 0; j < n; ++j) {
			// 每個數字大小在 [5,99] 之間
			outfile << randint(5, 99) << " ";
		}
		outfile << endl;
	}
	outfile.close();

	ifstream  infile(data);
	istringstream  istr;
	string    line;
	vector<int>  nums;
	int  no;

	i = 1;
	// 由 infile 檔讀入各列資料
	while (getline(infile, line)) {
		istr.str(line);

		// 讀入各列數字
		while (istr >> no) nums.push_back(no);
		istr.clear();

		cout << "[" << i++ << "]" << endl;

		// 列印數字，各個數字間有逗號
		cout_container(nums, " , ");

		// 依數字的各個數字和比大小，由大到小
		// 若數字和一樣則比數字大小，由大到小
		sort(nums.begin(), nums.end(), large_digit_sum());

		// 輸出比較後的結果
		cout_container(nums, " --> ");

		cout << endl;
		nums.clear();
	}
}
