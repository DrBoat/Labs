#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
 
using namespace std;

bool NextSet(int *a, int n, int m)
{
	int k = m;
	for (int i = k - 1; i >= 0; --i)
	{
		if (a[i] < n - k + i + 1) 
		{
			a[i]++;
			for (int j = i + 1; j < k; ++j)
			{
				a[j] = a[j - 1] + 1;
			}
			return true;
		}
	}
	return false;
}
void Print(int *a, int n) 
{
	static int num = 1; 
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int main() 
{
    freopen("choose.in", "r", stdin);
  	freopen("choose.out", "w", stdout);int n, m, *a;
	cin >> n >> m;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
	Print(a, m);
	if (n >= m)
	{
		while (NextSet(a, n, m))
		{
			Print(a, m);
		}
	}
	return 0;
}