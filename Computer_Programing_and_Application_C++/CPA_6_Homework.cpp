#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL,"zh_TW.UTF-8") ;

	int i, j, k;
	const int n = 7;

	wstring poem =
			L"春風和煦滿常山芍藥天麻及牡丹遠志去尋使君子當歸何必問澤蘭"
			L"夏半端陽五月天菖蒲製酒樂豐年庭前幾多紅娘子笑道檳郎應採蓮"
			L"秋菊開花遍地黃一回雨露一回香扶童便取國公酒醉到天南星大光"
			L"冬來無處不防風白紙糊窗重複重睡到雪消陽起時戶懸門外白頭翁";

	int  foo[7][7] = { -1 };

	const int D = 3;
	int s = 0;
	int t = 0;
	int ds[D] = { 1 , 0, -1 };
	int dt[D] = { 1 , -1, 0 };
	int d = 0;

	for (i = 0; i < 28; i++) {
		foo[s][t] = i;
		if ((s == 6 && t == 6) || ((s + t == n - 1) && (s > 4)) || (s == 5 && t == 4) || (s + t == 1) || (s == 3 && t == 1)) {
			d += 1;
			if (d == D) d = 0;
		}
		s += ds[d];
		t += dt[d];
	}

	for (i = 0; i < n; i++) {
		wcout << wstring(n - i, L' ');
		for (k = 0; k < 4; k++) {
			for (j = 0; j < i + 1; j++) {
				wcout << poem[4 * n*(3 - k) +foo[i][j]]; //
			}
			wcout << wstring(2 * (n - i), L' ');
		}
		cout << endl;
	}
}
