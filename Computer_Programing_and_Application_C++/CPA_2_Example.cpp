#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n,m,i,j,k;

	cout<< ">";
	cin >> n;
	m=(n-n%2)/2;

	for (i = 1; i <=n + m; i++) {
			for (j = 1; j <=n; j++) {
				for (k = 1; k <= n; k++) {
					if (j % 2 == 1) {
						if ((i - k >= 0) && (i < n+1 ))
						{
							cout << j;
						}
						else {
							cout << " ";
						}
					}

					else {
						if ((i-m - k -1< 0) && (i > m))
						{
							cout << j;
						}
						else
						{
							cout << " ";
						}
					}
					cout << " ";
				}
				cout << " ";
			}
			cout << endl;
		}

		system("pause");
		return 0;
}
