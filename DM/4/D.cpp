#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MOD = 1e9+7, MAXN = 110;

bool is_terminal[MAXN];
map<char, vector<int>> steps[MAXN];



int main()
{
	freopen("problem4.in", "r", stdin);
	freopen("problem4.out", "w", stdout);
	int n, m, k, l;
	cin >> n >> m >> k >> l;
	is_terminal.resize(n + 1);
	for (int i = 0; i < k; i++)
	{
		int tmp;
		cin >> tmp;
		is_terminal[tmp] = true;
	}
	map<char, int> *states = new map<char, int>[n + 1];
	for (int i = 0; i < m; i++)
	{
		int from, to;
		char c;
		cin >> from >> to >> c;
		states[from][c] = to;
	}
	vector<vector<int>> dp(n + 1, vector<int> (l + 1));
	for (int i = 0; i <= n; i++)
	{
		if (is_terminal[i]) dp[i][0] = 1;

	}
	for (int i = 1; i <= l; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (pair<char, int> nxt :states[j])
			{
				dp[j][i] += dp[nxt.second][i - 1];
				dp[j][i] %= MOD;
			}
		}
	}
	cout << dp[1][l];
}