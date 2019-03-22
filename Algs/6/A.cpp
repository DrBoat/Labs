
#include <iostream>
#include <vector>

using namespace std;

int const MAXN = 2e5 + 10;

struct elem
{
	int parent, h, time_in, time_out;
	vector<int> children;
};

vector<elem> tree;

int timer = 0;

int binup[19][MAXN];

void dfs(int v)
{
	tree[v].time_in = timer++;
	for (int i = 0; i < tree[v].children.size(); i++)
	{
		dfs(tree[v].children[i]);
	}
	binup[0][v] = tree[v].parent;
	tree[v].time_out = timer++;
}

bool is_parent(int u, int v)
{
	if (tree[u].time_in <= tree[v].time_in && tree[u].time_out >= tree[v].time_out) return true;
	return false;
}

int lca(int u, int v)
{
	if (is_parent(u, v)) return u;
	if (is_parent(v, u)) return v;
	for (int i = 18; i >= 0; i--)
	{
		if (!is_parent(binup[i][v], u))
		{
			v = binup[i][v];
		}
	}
	return tree[v].parent;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	tree.resize(n + 1);
	tree[1].parent = 1;
	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		tree[i].parent = x;
		tree[x].children.push_back(i);
	}
	dfs(1);
	for (int i = 1; i < 19; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			binup[i][j] = binup[i - 1][binup[i - 1][j]];
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