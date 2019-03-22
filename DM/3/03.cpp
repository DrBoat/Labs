#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector <string> codes;
long long n, k;

void make_gray_rev (int l, int r);

void make_gray (int l, int r)
{
	int m = (l + r)/2;
	for (int i = l; i < m; i++)
	{
		codes[i] += '0';
	}
	for (int i = m; i < r; i++)
	{
		codes[i] += '1';
	}
	if (r - l == 2) return;
	make_gray (l, m);
	make_gray_rev (m, r);
}

void make_gray_rev (int l, int r)
{
	int m = (l + r)/2;
	for (int i = l; i < m; i++)
	{
		codes[i] += '1';
	}
	for (int i = m; i < r; i++)
	{
		codes[i] += '0';
	}
	if (r - l == 2) return;
	make_gray (l, m);
	make_gray_rev (m, r);
}

int main()
{
	freopen("antigray.in", "r", stdin);
	freopen("antigray.out", "w", stdout);
	cin >> n;
	k = pow(3, n);
	codes.resize(k);
	string fs = "";
	for (int i = 0; i < n; i++)
	{
		fs += '0';
	}
	codes[0] = fs;
	for (int i = 1; i * 3 < k; i++)
	{
		string tmp = codes[(i - 1) * 3];
		tmp[n - 1]++;
		for (int j = n - 1; j >= 0; j--)
		{
			if (tmp[j] == '3')
			{
				tmp[j] = '0';
				tmp[j - 1]++;
			}
			else
			{
				break;
			}
		}
		codes[i * 3] = tmp;
	}
	for (int i = 0; i < k; i++)
	{
		if (i % 3)
		{
			codes[i] = codes[i - 1];
			for (int j = 0; j < n; j++)
			{
				codes[i][j]++;
				if (codes[i][j] == '3')
				{
					codes[i][j] = '0';
				}
			}
		}
		cout << codes[i] << endl;
	}
}