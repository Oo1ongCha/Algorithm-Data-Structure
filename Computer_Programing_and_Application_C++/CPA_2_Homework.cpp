#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int  n, m, i, j;

	cout << ">";
	cin >> n;
	while ((n < 0) || (9 < n))
	{
		cout << ">";
		cin >> n;
	}



	for (i = 1; i < 2*n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if(j - i == 1)
			{
				cout << endl;
				break;
			}

			else if (i - j + 1 < n)
			{
					cout << j;
					for (m = 1; m < n-1; m++)
					{
						cout << " ";
					}
					cout << j << " ";

					if (i > n -1 && j==n)
					{
						cout << endl;
						break;
					}
			}

			else if (i - j + 1 == n)
			{
				for (m = 1; m <= n; m++)
				{
					cout << j;
				}
				cout << " ";

				if (i > n - 1 && j == n)
				{
					cout << endl;
					break;
				}
			}

			else
			{
				for (m = 1; m < n+2; m++)
				{
					cout << " ";
				}
			}
		}
	}
	return 0;
}

