#include <iostream>
#include <vector>
using namespace std;

struct elem
{
	int level;
	int parent;
	vector<int> graph;
	vector<int> ans;
	int p;
	elem() : level(-1), parent(0), p(0) { };
};

const int MAXDEPTH = 20;
int n;
vector<elem> tree;

int dfs(int v, int size, int &center, int p = -1)
{
	int sum = 1;
	for (int x : tree[v].graph)
	{
		if (tree[x].level == -1 && x != p)
		{
			sum += dfs(x, size, center, v);
		}
	}
	if (center == -1 && (2 * sum >= size || p == -1))
	{
		center = v;
	}
	return sum;
}

void build(int v, int size, int depth, int last)
{
	int center = -1;
	dfs(v, size, center);
	tree[center].level = depth;
	tree[center].parent = last;
	for (int x : tree[center].graph)
	{
		if (tree[x].level == -1)
		{
			build(x, size / 2, depth + 1, center);
		}
	}
};

int main()
{
	cin >> n;
	tree.resize(n);
	for (int i = 0; i + 1 < n; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		tree[v].graph.push_back(u);
		tree[u].graph.push_back(v);
	}
	build(0, n, 0, -1);
	int start = -1;
	for (int i = 0; i < n; i++)
	{
		if (tree[i].parent == -1)
		{
			start = i;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (i != start)
		{
			tree[tree[i].parent].ans.push_back(i);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < tree[i].ans.size(); j++)
		{
			tree[tree[i].ans[j]].p = i;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (i == start)
		{
			cout << 0 << ' ';
		}
		else
		{
			cout << tree[i].p + 1 << ' ';
		}
	}
	cout << endl;
	return 0;
}