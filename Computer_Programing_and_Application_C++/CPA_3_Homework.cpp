#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int  n, m, i, j, k, l;

	cout << ">";
	cin >> n;




	for (i = 1; i < n + 1; i++) {
		k = n;
		for (j = 1; j < i + 1; j++) {
			if (i == j)
			{
				cout << k << endl;
				ptr[i][j] = k;
			}

			else
			{
				l = (rand() % (k - i + j)) + 1;
				cout << l << " ";
				ptr[i][j] = l;
				k = k - l;
			}
		}
	}
	cout << endl << endl;

	for (i = 1; i < n + 1; i++) {
		for (m = 1; m < 5; m++) {
			for (j = 1; j < n + 1; j++) {
				switch (m)
				{
				case 1:
					if (i + j < n + 2)
					{
						cout << ptr[n - j + 1][i] << " ";
					}

					else
					{
						cout << "  ";
					}
					break;
				case 2:
					if (i - j > -1)
					{
						cout << ptr[i][j] << " ";
					}

					else
					{
						cout << "  ";
					}
					break;
				case 3:
					if (i + j > n)
					{
						cout << ptr[j][n - i + 1] << " ";
					}

					else
					{
						cout << "  ";
					}
					break;
				case 4:
					if (i - j < 1)
					{
						cout << ptr[n - i + 1][n - j + 1] << " ";
						if (j == n)
						{
							cout << endl;
						}
					}

					else
					{
						cout << "  ";
					}
					break;
				}
			}
		}
	}

	for ( i = 1 ; i < m+1 ; i++ ) delete [] ptr[i] ;
	delete [] ptr ;

	return 0;
}
