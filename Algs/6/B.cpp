#include <iostream>
#include <vector>

using namespace std;

int const MAXN = 2e5 + 10, INF = 1e9 + 7;

struct elem
{
	int parent, h, time_in, time_out, cost;
	vector<int> children;
};

vector<elem> tree;

int timer = 0;

pair<int, int> binup[19][MAXN];

void dfs(int v)
{
	tree[v].time_in = timer++;
	for (int i = 0; i < tree[v].children.size(); i++)
	{
		dfs(tree[v].children[i]);
	}
	binup[0][v].first = tree[v].parent;
	binup[0][v].second = tree[v].cost;
	tree[v].time_out = timer++;
}

bool is_parent(int u, int v)
{
	if (tree[u].time_in <= tree[v].time_in && tree[u].time_out >= tree[v].time_out) return true;
	return false;
}

int lca(int u, int v)
{
	int v_in = v, mn = INF;
	if (is_parent(u, v))
	{
		for (int i = 18; i >= 0; i--)
		{
			if(!is_parent(binup[i][v].first, u))
			{
				mn = min(mn, binup[i][v].second);
				v = binup[i][v].first;
			}
		}
		return min(mn, binup[0][v].second);
	}
	if (is_parent(v, u))
	{
		for (int i = 18; i >= 0; i--)
		{
			if(!is_parent(binup[i][u].first, v))
			{
				mn = min(mn, binup[i][u].second);
				u = binup[i][u].first;
			}
		}
		return min(mn, binup[0][u].second);
	}
	for (int i = 18; i >= 0; i--)
	{
		if (!is_parent(binup[i][v].first, u))
		{
			mn = min(mn, binup[i][v].second);
			v = binup[i][v].first;
		}
	}
	mn = min(mn, binup[0][v].second);
	for (int i = 18; i >= 0; i--)
	{
		if(!is_parent(binup[i][u].first, v))
		{
			mn = min(mn, binup[i][u].second);
			u = binup[i][u].first;
		}
	}
	return min(mn, binup[0][u].second);
}

int main()
{
	freopen("minonpath.in", "r", stdin);
	freopen("minonpath.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	tree.resize(n + 1);
	tree[1].parent = 1;
	tree[1].cost = INF;
	for (int i = 2; i <= n; i++)
	{
		int x, cost;
		cin >> x >> cost;
		tree[i].parent = x;
		tree[i].cost = cost;
		tree[x].children.push_back(i);
	}
	dfs(1);
	for (int i = 1; i < 19; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			binup[i][j].first = binup[i - 1][binup[i - 1][j].first].first;
			binup[i][j].second = min(binup[i - 1][j].second, binup[i - 1][binup[i - 1][j].first].second);
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << endl;
	}
}