#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <string> codes;

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
	freopen("gray.in", "r", stdin);
	freopen("gray.out", "w", stdout);
	long long n;
	cin >> n;
	int k = 1 << n;
	codes.resize(k);
	make_gray (0, k);
	for (int i = 0; i < k; i++)
	{
		cout << codes[i] << endl;
	}
}