// Homework 9.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int main() {
	const int N = 2, R = 5, C = 5;
	int bitmap[N][R] = { {0x4,0x1f,0x15,0x1f,0x4} , {0x4,0x1f,0x4,0xa,0x11} };
	string ncu = "中大";
	cout << ncu[0] << ncu[1] << ncu[2] << endl; //

	int i, j, k, n, h, t, s, v, u;
	s = 0;

	while (1) {
		cout << "> ";
		cin >> n;

		for (s = 0; s < 2; ++s) {	// 上下兩字
			for (v = 0; v < R*n; ++v) {	// 每個字的縱向迴圈次數
				h = (s ? v + 1 : R * n - v);
				for (t = 0; t < 2 * n - 1; ++t) {	// 每個字的橫向字數
					k = n - abs(n - 1 - t);
					if (h > k*R) {
						cout << string(2 * k*C, ' ');
					}
					else {
						i = (s ? R - 1 - (k*R - h) / k : (k*R - h) / k);
						for (j = C - 1; j >= 0; --j) {	// 每個字內點陣迴圈
							if (bitmap[s][i] & (1 << j)) {
								for (u = 0; u < k; ++u) {
									cout << ncu[3 * s] << ncu[3 * s + 1] << ncu[3 * s + 2];
								}
							}
							else cout << string(2 * k, ' ');
						}
					}
					cout << " ";
				}
				cout << endl;
			}
		}
		cout << endl;
	}
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