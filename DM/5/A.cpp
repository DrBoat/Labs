#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<char, map<char, vector<char>>> productions;

bool dfs(char v, int ind, string &s)
{
	if (ind == (int)s.size())
	{
		return v == '-';
	}
	bool res = false;
	for (auto u:productions[v][s[ind]])
	{
		res = res || dfs(u, ind + 1, s);
	}
	return res;
}

int main()
{
	freopen("automaton.in", "r", stdin);
	freopen("automaton.out", "w", stdout);
	int n;
	char start;
	cin >> n >> start;
	for (int i = 0; i < n; i++)
	{
		char from;
		string to, tmp;
		cin >> from >> tmp >> to;
		if ((int)to.size() == 1)
		{
			productions[from][to[0]].push_back('-');
		}
		else
		{
			productions[from][to[0]].push_back(to[1]);
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		cout << (dfs(start, 0, s) ? "yes\n" : "no\n");
	}
}