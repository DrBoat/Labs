#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9+7;

int main()
{
	int n;
	cin >> n;
	vector <int> a(n), d(n + 1), p(n + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
		p[i] = -1;
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i])
			{
				if (d[j] > d[i] - 1)
				{
					d[i] = d[j] + 1;
					p[i] = j;
				}
			}
		}
	}
	int ans = d[0],  pos = 0;
	for (int i = 0; i < n; i++)
	{
		if (d[i] > ans)
		{
			ans = d[i];
			pos = i;
		}
	}
	vector<int> out;
	while (pos >= 0)
	{
		out.push_back(pos);
		pos = p[pos];
	}
	cout << out.size() << endl;
	for (int i = out.size(); i > 0; i--)
	{
		cout << a[out[i - 1]] << ' ';
	}

}