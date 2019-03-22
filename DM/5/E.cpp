#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;

const long long MOD = 1e9+7;

map<char, map<char, bool>> way;
map<char, vector<string>> productions;
map<char, vector<vector<long long>>> dp;
set<char> nt;

long long dp_calc(string s, char start)
{
	for (auto A : nt)
	{
		dp[A] = vector<vector<long long>>(101, vector<long long>(101, 0));
		for (int i = 0; i < (int)s.size(); i++)
		{
            if (way[A].count(s[i]) > 0)
            {
                dp[A][i][i + 1] = 1;
            }
        }
        if (way[A].count('-') > 0)
        {
            dp[A][i][i] = 1;
        }
	}
	for (int m = 1; m < (int)s.size() ; m++)
	{
        for (int i = 0; i < (int)s.size() - m; i++)
        {
            int j = i + m;
            for (auto A : nt)
            {
                for (auto B : productions[A])
                {
                    for (int k = i; k < j; k++)
                    {
                        dp[A][i][j] += dp[B[0]][i][k] * dp[B[1]][k + 1][j];
                        dp[A][i][j] %= MOD;
                    }
                }
            }
        }
    }
	return dp[start][0][(int)s.size() - 1];
}

int main()
{
	freopen("cf.in", "r", stdin);
	freopen("cf.out", "w", stdout);
	int n;
	char start;
	cin >> n >> start;
	{
        string tmp;
        getline(cin, tmp);
    }
	for (int i = 0; i < n; i++)
	{
		char from;
		string tmp, to = "";
		getline(cin, tmp);
		stringstream ss(tmp);
		ss >> from;
		if ((int)tmp.size() != 4)
		{
			ss >> tmp >> to;
		}
		if ((int)to.size() == 0)
		{
			to = "-";
		}
		nt.insert(from);
		if ((int)to.size() != 2)
		{
			way[from][to[0]] = true;
		}
		else
		{
			nt.insert(to[0]);
			nt.insert(to[1]);
			productions[from].push_back(to);
		}
	}
	string s;
	cin >> s;
	cout << dp_calc(s, start) << endl;
}