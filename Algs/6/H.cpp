#include <iostream>
#include <vector>
#include <set>

using namespace std;

int const MAXN = 1e6 + 5;
int color[MAXN], res[MAXN];
set<int> s[MAXN];
vector<vector<int>> tree;

void add(set<int> &a, set<int> &b)
{
	if (a.size() < b.size())
	{
		a.swap(b);
	}
	set<int>::iterator iter;
	for(iter = b.begin(); iter != b.end(); iter++)
	{
		a.insert(*iter);
	}
	b.clear();
}

void dfs(int v)
{
	s[v].insert(color[v]);
	for(int i = 0; i < tree[v].size(); i++)
	{
		int u = tree[v][i];
		dfs(u);
		add(s[v], s[u]);
	}
	res[v] = s[v].size();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	tree.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int p, c;
		cin >> p >> c;
		tree[p].push_back(i);
		color[i] = c;
	}
	dfs(0);
	for(int i = 1; i <= n; i++)
	{
		cout << res[i] << ' ';
	}
}