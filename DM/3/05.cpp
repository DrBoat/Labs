#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector <string> codes;

void make_gray_rev (int l, int r, int k);

void make_gray (int l, int r, int k)
{
	for (int i = 0; i < k; i++)
	{
		int tmp = l + (r - l) * i / k;
		for (int j = tmp; j < tmp + (r - l) / k; j++)
		{
			char c = '0' + i;
			codes[j] += c;
		}
		if (i % 2 == 0)
		{
			if (r - l != k) make_gray (tmp, tmp + (r - l) / k, k);
		}
		else
		{
			if (r - l != k) make_gray_rev (tmp, tmp + (r - l) / k, k);
		}
	}
}

void make_gray_rev (int l, int r, int k)
{
	for (int i = 0; i < k; i++)
	{
		int tmp = l + (r - l) * i / k;
		for (int j = tmp; j < tmp + (r - l) / k; j++)
		{
			char c = '0' + (k - i - 1);
			codes[j] += c;
		}
		if (i % 2 == 0)
		{
			if (r - l != k)
			{
				if (k % 2 == 1)
				{
					make_gray_rev (tmp, tmp + (r - l) / k, k);
				}
				else
				{
					make_gray (tmp, tmp + (r - l) / k, k);
				}
			}
		}
		else
		{
			if (r - l != k)
			{
				if (k % 2 == 1)
				{
					make_gray (tmp, tmp + (r - l) / k, k);
				}
				else
				{
					make_gray_rev (tmp, tmp + (r - l) / k, k);
				}
			}
		}
	}
}

int main()
{
	freopen("telemetry.in", "r", stdin);
	freopen("telemetry.out", "w", stdout);
	long long n, l;
	cin >> n >> l;
	int k = pow(l, n);
	codes.resize(k);
	make_gray (0, k, l);
	for (int i = 0; i < k; i++)
	{
		cout << codes[i] << endl;
	}
}