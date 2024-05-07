#include <iostream>
#include <string>

using namespace std;

int main()
{
 int i, j, k, l, m;

 string poem =
  "春風和煦滿常山芍藥天麻及牡丹遠至去尋使君子當歸何必問澤蘭"
  "秋菊開花遍地黃一回雨露一回香扶童便取國公酒醉到天南星大光"
  "夏半端陽五月天菖蒲製酒樂豐年庭前幾多紅娘子笑到檳榔應採蓮"
  "冬來無處不防風白紙糊窗重複重睡到雪消陽起時戶懸門外白頭翁";

 int foo[7][7] = { -1 };

 const int D = 3;
 int s = 0;
 int t = 0;
 int ds[D] = { 1,0,-1 };
 int dt[D] = { 1,-1,0 };
 int d = 0;

 for (k = 0; k < 28; k++) {
  foo[s][t] = k;

  if (((s > 4) && (s + t == 6)) || ((s == 5) && (t == 4)) || ((s == 6) && (t == 6)) || ((s == 1) && (t == 0)) || ((s == 3) && (t == 1))) {
   d += 1;
   if (d == D) d = 0;
  }
  s += ds[d];
  t += dt[d];
 }

 for (i = 0; i < 2; i++) {
  for (l = 0; l < 7 + 1; l++) {
   for (k = 0; k < 2 * i + 1; k++) {
    if (k == 0) cout << string(10 * (1 - i) + 7 - l, ' ');
    if (k % 2 == 1 && l < 8) {
     for (j = 0; j < 7 - l; j++) {
      m = foo[7 - l - 1][j] + 28 * (k + 1);
      cout << poem[2 * m] << poem[2 * m + 1];
     }
     cout << "   ";
    }
    else {
     for (j = 0; j < l; j++) {
      m = foo[l - 1][j] + 28 * i* (k + 1);
      cout << poem[2 * m] << poem[2 * m + 1];
     }
     cout << "   ";
    }
   }
   cout << endl;
  }
  cout << endl;
 }
}
