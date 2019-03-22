#include <iostream>

using namespace std;

int main()
{
	freopen("allvectors.in", "r", stdin);
	freopen("allvectors.out", "w", stdout);
	long long n;
	cin >> n;
	int k = 1 << n;
	for (int i = 0; i < k; i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if ((i & (1 << j)))
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
		}
		cout << endl;
	}
}