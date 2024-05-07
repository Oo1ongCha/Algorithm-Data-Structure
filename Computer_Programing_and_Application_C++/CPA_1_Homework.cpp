#include <iostream>
#include <iomanip>

using namespace std;

void yang(int l, int k, char a) //央
{
	if (l == 4)
	{
		cout << a ;
	}
	else if (k==3 & l<5 )
	{
		cout << a;
	}
	else if (l == 2 )
	{
		if (k < 6 & k>0)
		{
			cout << a;
		}
		else
		{
			cout << " ";
		}
	}
	else if (l == 3 & k % 2 != 0)
	{
		cout << a;
	}
	else if (l == 5 )
	{
		if (k == 2 || k == 4)
		{
			cout << a;
		}
		else
		{
			cout << " ";
		}
	}
	else if (l == 6 )
	{
		if (k < 2 || k>4)
		{
			cout << a;
		}
		else
		{
			cout << " ";
		}
	}
	else
	{
		cout << " ";
	}

}

int main()
{
	int i, j, k, l;

	for (i = 0; i < 5; i++) //中 橫列
	{
		for (l = 0; l < 7; l++)//央 橫列
		{
			for (j = 0; j < 5; j++) //中
			{
				for (k = 0; k < 7; k++)//央 直行
				{
					if (i == 1)
					{
						yang(l, k, '*');
					}
					else if (i == 3)
					{
						yang(l, k, '*');
					}
					else if (j == 2)
					{
						yang(l, k, '*');
					}
					else if (i == 2 & j % 2 == 0)
					{
						yang(l, k, '*');
					}
					else
					{
						cout << " ";
					}
					cout << " ";
				}
				cout << " ";
			}
		cout << endl;
		}
	}
}
