#include <iostream>
#include <string>

using namespace std;

int num_0(int n) {
 int m;
 int num[5] = { 15,9,9,9,15 };
 m = num[n];
 return m;
}

int num_1(int n) {
 int m;
 int num[5] = { 2,2,2,2,2 };
 m = num[n];
 return m;
}

int num_2(int n) {
 int m;
 int num[5] = { 15,1,15,8,15 };
 m = num[n];
 return m;
}

int num_3(int n) {
 int m;
 int num[5] = { 15,1,7,1,15 };
 m = num[n];
 return m;
}

int num_4(int n) {
 int m;
 int num[5] = { 10,10,15,2,2 };
 m = num[n];
 return m;
}

int num_5(int n) {
 int m;
 int num[5] = { 15,8,15,1,15 };
 m = num[n];
 return m;
}

int num_6(int n) {
 int m;
 int num[5] = { 15,8,15,9,15 };
 m = num[n];
 return m;
}

int num_7(int n) {
 int m;
 int num[5] = { 15,9,1,1,1 };
 m = num[n];
 return m;
}

int num_8(int n) {
 int m;
 int num[5] = { 15,9,15,9,15 };
 m = num[n];
 return m;
}

int num_9(int n) {
 int m;
 int num[5] = { 15,9,15,1,15 };
 m = num[n];
 return m;
}

void print_little(int num, int n) {
 int i;
 for (i = 3; i >= 0; i--) {
  if ((num >> i) % 2 == 1) {
   cout << n;
  }
  else {
   cout << " ";
  }
 }
}

void print_big(int num, int m, int l) {
 int i;
 for (i = 3; i >= 0; i--) {
  if ((num >> i) % 2 == 1) {
   print_little(l, m);
   cout << " ";
  }
  else {
   cout << string(5, ' ');
  }
 }
}

int main()
{
 int i, j, k, l, m, n;
 char num;
 int number1[20];
 int  number2[20];
 cout << ">";
 cin >> n;
 i = 0;
 l = 0;

 while (n > 0) {
  number1[19 - i] = n % 10;
  i++;
  n = n / 10;
  l++;
 }

 for (i = 0; i < l; i++) {
  number2[l - i - 1] = number1[19 - i];
 }

 for (i = 0; i < 5; i++) { //大行
  for (l = 0; l < 5; l++) { //小行
   for (j = 0; j < 10; j++) { //幾個數字
    num = number2[j] + 48;
    switch (num) {
    case '0':
     print_big(num_0(i), 0, num_0(l));
     cout << " ";
     break;

    case '1':
     print_big(num_1(i), 1, num_1(l));
     cout << " ";
     break;

    case '2':
     print_big(num_2(i), 2, num_2(l));
     cout << " ";
     break;

    case '3':
     print_big(num_3(i), 3, num_3(l));
     cout << " ";
     break;

    case '4':
     print_big(num_4(i), 4, num_4(l));
     cout << " ";
     break;

    case '5':
     print_big(num_5(i), 5, num_5(l));
     cout << " ";
     break;

    case '6':
     print_big(num_6(i), 6, num_6(l));
     cout << " ";
     break;

    case '7':
     print_big(num_7(i), 7, num_7(l));
     cout << " ";
     break;

    case '8':
     print_big(num_8(i), 8, num_8(l));
     cout << " ";
     break;

    case '9':
     print_big(num_9(i), 9, num_9(l));
     cout << " ";
     break;
    }
    cout << "  ";
   }
   cout << endl;
  }
  cout << endl;
 }

}
