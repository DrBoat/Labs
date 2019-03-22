#include <iostream>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector <int> a(n), dp(n), p(1);
	for (int i = 1; i < n - 1; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; i++)
	{
		int mx = dp[i - 1], ind = i - 1;
		for (int j = 1; j <= k; j++)
		{
			if (i - j >= 0)
			{
				if (mx < dp[i - j])
				{
					ind = i - j;
					mx = dp[i - j];
				}
			}
		}
		dp[i] = mx + a[i];
		p.push_back(ind + 1);
	}
	cout << dp[dp.size() - 1] << endl;
	vector <int> ans;
	ans.push_back(n);
	int i = n - 1;
	while (i != 0)
	{
		ans.push_back(p[i]);
		i = p[i] - 1;
	}
	cout << ans.size() - 1 << endl;
	for (i = ans.size(); i > 0; i--)
	{
		cout << ans[i - 1] << ' ';
	}
}